
#include <algorithm>
#include <bitset>
#include <chrono>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <numeric>
#include <random>
#include <ratio>
#include <tuple>
#include <utility>
#include <valarray>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;


template <typename _Ty>
struct is_container : false_type {};
template <typename _Ty, typename _Alloc>
struct is_container<vector<_Ty, allocator<_Alloc>>> : true_type {};


template <typename _Ty>
struct clone_from { using type = _Ty; };
template <typename _Ty>
using clone_from_t = typename clone_from<decay_t<_Ty>>::type;
template <typename _Ty, typename _Alloc>
struct clone_from<vector<_Ty, allocator<_Alloc>>> { using type = decay_t<vector<clone_from_t<_Ty>, allocator<clone_from_t<_Alloc>>>>; };


template <typename _Ty>
constexpr decay_t<_Ty> clone(clone_from_t<_Ty> const & _Arg);

template <typename _Ty1, typename _Ty2>
constexpr _Ty1 & construct(_Ty1 & _Left, _Ty2 const & _Right);
template <typename _Ty>
constexpr _Ty & construct(_Ty & _Left, _Ty const & _Right, false_type) { return _Left = move(_Ty(_Right)); }
template <typename _Ty>
constexpr _Ty & construct(_Ty & _Left, clone_from_t<_Ty> const & _Right, true_type) {
  _Left.resize(_Right.size());
  auto l = begin(_Left);
  for (auto r = begin(_Right); r != end(_Right); ++r) {
    *l = clone<typename _Ty::value_type>(*r);
    ++l;
  }
  return _Left;
}
template <typename _Ty1, typename _Ty2>
constexpr _Ty1 & construct(_Ty1 & _Left, _Ty2 const & _Right) { return construct(_Left, _Right, typename is_container<_Ty1>::type()); }

template <typename _Ty>
constexpr decay_t<_Ty> clone(clone_from_t<_Ty> const & _Arg) {
  decay_t<_Ty> _Lhs;
  return move(construct(_Lhs, _Arg));
}


template <typename _Ty>
constexpr _Ty forward_to(decay_t<_Ty> && _Arg, false_type, false_type) { return move(_Arg); }
template <typename _Ty>
constexpr _Ty forward_to(decay_t<_Ty> && _Arg, true_type, false_type) { return _Arg; }
template <typename _Ty>
constexpr _Ty forward_to(decay_t<_Ty> && _Arg, false_type, true_type) { return const_cast<decay_t<_Ty> &>(_Arg); }
template <typename _Ty>
constexpr _Ty forward_to(decay_t<_Ty> && _Arg) { return forward_to<_Ty>(forward<decay_t<_Ty>>(_Arg), typename is_const<_Ty>::type(), typename is_reference<_Ty>::type()); }


template <typename _Ty>
constexpr bool compare(_Ty const & _Left, _Ty const & _Right) { return _Left == _Right; }


template <typename _Elem, typename _Traits>
constexpr basic_ostream<_Elem, _Traits> & print(basic_ostream<_Elem, _Traits> & _Ostr) { return _Ostr; }
template <typename _Elem, typename _Traits, typename _Ty>
constexpr basic_ostream<_Elem, _Traits> & print(basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg);
template <typename _Elem, typename _Traits, typename _Ty>
constexpr basic_ostream<_Elem, _Traits> & print(basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, false_type) {
  return _Ostr << _Arg;
}
template <typename _Elem, typename _Traits, typename _Ty>
constexpr basic_ostream<_Elem, _Traits> & print(basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, true_type) {
  _Ostr << "[";
  for (auto const & _Val : _Arg) { print(_Ostr << " ", _Val); }
  return _Ostr << " ]";
}
template <typename _Elem, typename _Traits, typename _Ty>
constexpr basic_ostream<_Elem, _Traits> & print(basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg) {
  return print(_Ostr, _Arg, typename is_container<_Ty>::type());
}
template <typename _Elem, typename _Traits, typename _Ty, typename... _Types>
constexpr basic_ostream<_Elem, _Traits> & print(basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, _Types const &... _Args) {
  return print(print(_Ostr, _Arg) << ", ", _Args...);
}


template <bool = false>
struct Sorter {
  template <typename _Ty>
  constexpr void operator()(_Ty & _Arg) const {}
};
template <>
struct Sorter<true> {
  template <typename _Ty>
  constexpr void operator()(_Ty & _Arg) const { sort(_Arg.begin(), _Arg.end()); }
};


template <bool _Sort, typename _Solution, typename _Ty, typename... _Types>
class Checker {
public:
  explicit Checker(_Ty (_Solution::*_Func)(_Types...)) : f(_Func), X(0), Q(0) {
    cout << boolalpha << title << endl;
  }
  virtual ~Checker() {
    cout << "Point: " << (Q - X) << " / " << Q << endl;
  }

  void operator()(clone_from_t<_Ty> && _Ans, clone_from_t<_Types> &&... _Args) {
    _Solution t;
    _Ty && ans = (t.*f)(forward_to<_Types>(clone<_Types>(_Args))...);
    _Ty && _ans = clone<_Ty>(_Ans);

    Sorter<_Sort && is_container<_Ty>::value> sort;
    sort(ans);
    sort(_ans);

    ++Q;
    if (!compare(ans, _ans)) {
      print(cout << Q << " Q: ", clone<_Types>(_Args)...) << endl;
      print(cout << Q << " O: ", _ans) << endl;
      print(cout << Q << " X: ", ans) << endl;
      ++X;
    }
  }

private:
  _Ty (_Solution::*f)(_Types...);
  size_t X, Q;
  static string const title;
};

template <bool _Sort, typename _Solution>
class Checker<_Sort, _Solution, void> {
public:
  explicit Checker(void (_Solution::*_Func)()) : f(_Func), X(0), Q(0) {
    cout << title << endl;
  }

  virtual ~Checker() {
    cout << "Point: " << (Q - X) << " / " << Q << endl;
  }

  void operator()() {
    _Solution t;
    (t.*f)();

    ++Q;
  }

private:
  void (_Solution::*f)();
  size_t X, Q;
  static string const title;
};

#define Settings                                                              \
  template <bool _Sort, typename _Solution, typename _Ty, typename... _Types> \
  string const Checker<_Sort, _Solution, _Ty, _Types...>::title = __FILE__;   \
  template <bool _Sort, typename _Solution>                                   \
  string const Checker<_Sort, _Solution, void>::title = __FILE__;

template <typename _Ty, typename _Ret, typename... _Types>
Checker<false, _Ty, _Ret, _Types...> solve(_Ret (_Ty::*_Func)(_Types...)) {
  return Checker<false, _Ty, _Ret, _Types...>(_Func);
}
template <typename _Ty, typename _Ret, typename... _Types>
Checker<true, _Ty, _Ret, _Types...> solve_unordered(_Ret (_Ty::*_Func)(_Types...)) {
  return Checker<true, _Ty, _Ret, _Types...>(_Func);
}


template <>
struct clone_from<vector<char>> { using type = string; };
template <>
vector<char> & construct(vector<char> & _Left, clone_from_t<vector<char>> const & _Arg) {
  return _Left = move(vector<char>(_Arg.begin(), _Arg.end()));
}


template <>
constexpr bool compare(double const & _Left, double const & _Right) {
  if (_Left == _Right) return true;
  return abs(_Left - _Right) / (abs(_Left) + abs(_Right)) < 0.000001;
}


template <typename _Ty>
struct ListNode_ {
  _Ty val;
  ListNode_<_Ty> * next;
  ListNode_(_Ty const & x) : val(x), next(nullptr) {}
};
using ListNode = ListNode_<int>;

template <typename _Ty>
struct clone_from<ListNode_<_Ty> *> { using type = vector<clone_from_t<_Ty>>; };
template <typename _Ty>
constexpr ListNode_<_Ty> *& construct(ListNode_<_Ty> *& _Left, clone_from_t<ListNode_<_Ty> *> const & _Arg) {
  _Left = nullptr;
  auto p = &_Left;
  for (auto const & _Val : _Arg) {
    *p = new ListNode_<_Ty>(clone<_Ty>(_Val));
    p = &(*p)->next;
  }
  return _Left;
}
template <typename _Ty>
constexpr bool compare(ListNode_<_Ty> * const & _Left, ListNode_<_Ty> * const & _Right) {
  auto l = _Left, r = _Right;
  while ((l != nullptr) && (r != nullptr)) {
    if (!compare(l->val, r->val)) return false;
    l = l->next;
    r = r->next;
  }
  if ((l != nullptr) || (r != nullptr)) return false;
  return true;
}
template <typename _Elem, typename _Traits, typename _Ty>
constexpr basic_ostream<_Elem, _Traits> & print(basic_ostream<_Elem, _Traits> & _Ostr, ListNode_<_Ty> * const & _Arg) {
  _Ostr << "(";
  auto p = _Arg;
  while (p != nullptr) {
    print(_Ostr << "> ", p->val);
    p = p->next;
  }
  return _Ostr << " )";
}
