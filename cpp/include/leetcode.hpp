
#pragma once

#include "stl.hpp"

using namespace std;


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
constexpr _Ty & _construct1(_Ty & _Left, _Ty const & _Right, basic_data_tag) { return _Left = _Right; }
template <typename _Ty>
constexpr _Ty & _construct1(_Ty & _Left, _Ty const & _Right, element_data_tag) { return _Left = move(_Ty(_Right)); }
template <typename _Ty>
constexpr _Ty & _construct1(_Ty & _Left, clone_from_t<_Ty> const & _Right, container_data_tag) {
  _Left.resize(_Right.size());
  auto l = begin(_Left);
  for (auto r = begin(_Right); r != end(_Right); ++r) {
    *l = clone<typename _Ty::value_type>(*r);
    ++l;
  }
  return _Left;
}
template <typename _Ty1, typename _Ty2>
constexpr _Ty1 & construct(_Ty1 & _Left, _Ty2 const & _Right) { return _construct1(_Left, _Right, typename data_traits<_Ty2>::data_category()); }

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
constexpr bool compare(_Ty const & _Left, _Ty const & _Right);
template <typename _Ty>
constexpr bool _compare1(_Ty const & _Left, _Ty const & _Right, basic_data_tag) { return _Left == _Right; }
template <typename _Ty>
constexpr bool _compare1(_Ty const & _Left, _Ty const & _Right, element_data_tag) { return _Left == _Right; }
template <typename _Ty>
constexpr bool _compare1(_Ty const & _Left, _Ty const & _Right, container_data_tag) {
  if (_Left.size() != _Right.size()) return false;
  auto itRight = _Right.begin();
  for (auto it = _Left.begin(); it != _Left.end(); ++it, ++itRight)
    if (!compare(*it, *itRight)) return false;
  return true;
}
template <typename _Ty>
constexpr bool compare(_Ty const & _Left, _Ty const & _Right) { return _compare1(_Left, _Right, typename data_traits<_Ty>::data_category()); }


template <bool = false>
struct Sorter {
  template <typename _Ty>
  constexpr _Ty & operator()(_Ty & _Arg) const { return _Arg; }
};
template <>
struct Sorter<true> {
  template <typename _Ty>
  constexpr _Ty & operator()(_Ty & _Arg) const {
    sort(_Arg.begin(), _Arg.end());
    return _Arg;
  }
};


template <bool _Sort, typename _Solution, typename _Ty, typename... _Types>
class Checker {
public:
  explicit Checker(_Ty (_Solution::*_Func)(_Types...)) : f(_Func), X(0), Q(0) { cout << boolalpha << title << endl; }
  virtual ~Checker() { cout << "Point: " << (Q - X) << " / " << Q << endl; }

  void operator()(clone_from_t<_Ty> const & _Ans, clone_from_t<_Types> const &... _Args) {
    auto cerr_buffer = cerr.rdbuf(nullptr);
    check(_Ans, _Args...);
    cerr.rdbuf(cerr_buffer);
  }
  void debug(clone_from_t<_Ty> const & _Ans, clone_from_t<_Types> const &... _Args) { check(_Ans, _Args...); }

private:
  void check(clone_from_t<_Ty> const & _Ans, clone_from_t<_Types> const &... _Args) {
    _Solution s;
    _Ty && ans = (s.*f)(forward_to<_Types>(clone<_Types>(_Args))...);
    _Ty && _ans = clone<_Ty>(_Ans);

    Sorter<_Sort> sort;
    sort(_ans);
    sort(ans);

    ++Q;
    if (!compare(ans, _ans)) {
      write(cout << Q << " Q: ", make_tuple(clone<_Types>(_Args)...)) << endl;
      write(cout << Q << " O: ", _ans) << endl;
      write(cout << Q << " X: ", ans) << endl;
      ++X;
    }
  }

  _Ty (_Solution::*f)(_Types...);
  size_t X, Q;
  static string const title;
};

template <bool _Sort, typename _Solution>
class Checker<_Sort, _Solution, void> {
public:
  explicit Checker(void (_Solution::*_Func)()) : f(_Func), X(0), Q(0) { cout << boolalpha << title << endl; }
  virtual ~Checker() { cout << "Point: " << (Q - X) << " / " << Q << endl; }

  void operator()() {
    _Solution s;
    (s.*f)();

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
Checker<false, _Ty, _Ret, _Types...> solve(_Ret (_Ty::*_Func)(_Types...)) { return Checker<false, _Ty, _Ret, _Types...>(_Func); }
template <typename _Ty, typename _Ret, typename... _Types>
Checker<true, _Ty, _Ret, _Types...> solve_unordered(_Ret (_Ty::*_Func)(_Types...)) { return Checker<true, _Ty, _Ret, _Types...>(_Func); }


template <>
struct clone_from<vector<char>> { using type = string; };
template <>
vector<char> & construct(vector<char> & _Left, clone_from_t<vector<char>> const & _Arg) { return _Left = move(vector<char>(_Arg.begin(), _Arg.end())); }


template <>
constexpr bool compare(double const & _Left, double const & _Right) { return _Left == _Right || abs(_Left - _Right) / (abs(_Left) + abs(_Right)) < 0.000001; }


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
constexpr basic_ostream<_Elem, _Traits> & write(basic_ostream<_Elem, _Traits> & _Ostr, ListNode_<_Ty> * const & _Arg) {
  _Ostr << "(";
  auto p = _Arg;
  while (p != nullptr) {
    write(_Ostr << "> ", p->val);
    p = p->next;
  }
  return _Ostr << " )";
}

template <typename _Ty>
class Tree {
public:
  using _Myt = Tree<_Ty>;

  Tree() : _Null(true) {}
  Tree(_Ty const & val, initializer_list<_Myt> const & children = {}) : _Null(false), _Val(val), _Children(children) {}

  inline operator bool() const { return !_Null; }
  inline operator _Ty() const { return _Val; }
  typename vector<_Myt>::const_iterator begin() const { return _Children.begin(); }
  typename vector<_Myt>::const_iterator end() const { return _Children.end(); }

private:
  bool _Null;
  _Ty _Val;
  vector<_Myt> _Children;
};

template <typename _Ty>
struct TreeNode_ {
  _Ty val;
  TreeNode_<_Ty> * left;
  TreeNode_<_Ty> * right;
  TreeNode_(_Ty const & x) : val(x), left(nullptr), right(nullptr) {}
};
using TreeNode = TreeNode_<int>;

template <typename _Ty>
struct clone_from<TreeNode_<_Ty> *> { using type = Tree<clone_from_t<_Ty>>; };
template <typename _Ty>
constexpr TreeNode_<_Ty> *& construct(TreeNode_<_Ty> *& _Left, clone_from_t<TreeNode_<_Ty> *> const & _Arg) {
  _Left = nullptr;
  if (_Arg) {
    _Left = new TreeNode_<_Ty>(clone<_Ty>(_Arg));
    auto p = _Arg.begin();
    if (p != _Arg.end()) {
      construct(_Left->left, *p);
      ++p;
      if (p != _Arg.end()) construct(_Left->right, *p);
    }
  }
  return _Left;
}
template <typename _Ty>
constexpr bool compare(TreeNode_<_Ty> * const & _Left, TreeNode_<_Ty> * const & _Right) {
  auto l = _Left, r = _Right;
  if ((l != nullptr) && (r != nullptr)) {
    if (!compare(l->val, r->val)) return false;
    if (!compare(l->left, r->left)) return false;
    if (!compare(l->right, r->right)) return false;
  }
  return true;
}
template <typename _Elem, typename _Traits, typename _Ty>
constexpr basic_ostream<_Elem, _Traits> & write(basic_ostream<_Elem, _Traits> & _Ostr, TreeNode_<_Ty> * const & _Arg) {
  if (_Arg) {
    switch (0) {
    default:
    case 0:
      write(_Ostr << "( ", _Arg->val);
      if (_Arg->left) write(_Ostr << " <", _Arg->left);
      if (_Arg->right) write(_Ostr << " >", _Arg->right);
      _Ostr << " )";
      break;
    case 1:
      _Ostr << "( ";
      if (_Arg->left) write(_Ostr, _Arg->left) << "< ";
      write(_Ostr, _Arg->val);
      if (_Arg->right) write(_Ostr << " >", _Arg->right);
      _Ostr << " )";
      break;
    }
  }
  return _Ostr;
}


template <typename _Ty>
struct Interval_ {
  _Ty start;
  _Ty end;
  Interval_() : start(0), end(0) {}
  Interval_(_Ty s, _Ty e) : start(s), end(e) {}
};
using Interval = Interval_<int>;

template <typename _Ty>
constexpr bool compare(Interval_<_Ty> const & _Left, Interval_<_Ty> const & _Right) { return _Left.start == _Right.start && _Left.end == _Right.end; }
template <typename _Elem, typename _Traits, typename _Ty>
constexpr basic_ostream<_Elem, _Traits> & write(basic_ostream<_Elem, _Traits> & _Ostr, Interval_<_Ty> const & _Arg) {
  return _Ostr << "{" << _Arg.start << " " << _Arg.end << "}";
}
