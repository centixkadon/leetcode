
#include "leetcode.hpp"

struct Elem {
  Elem(size_t _v = 0) : v(_v) {}
  size_t v;
};

class Solution {
public:
  void test() { return; }
  size_t vec(vector<int> v1, vector<int> & v2, vector<int> const & v3) { return v1.size() + v2.size() + v3.size(); }
  size_t elem(Elem const & e) { return e.v; }
  bool mix(vector<ListNode *> & v1, ListNode_<vector<ListNode_<vector<size_t>> *>> * v2) { return true; }
  vector<size_t> unordered(vector<size_t> v) { return move(v); }
};

int main() {
  {
    auto check = solve(&Solution::vec);
    check(5, { 1 }, { 2, 3 }, { 4, 5, 6 }); // false
    check(6, { 1 }, { 2, 3 }, { 4, 5, 6 }); // true
    check(7, { 1 }, { 2, 3 }, { 4, 5, 6 }); // false
  }
  {
    auto check = solve(&Solution::elem);
    check(5, { 4 }); // false
  }
  {
    auto check = solve(&Solution::mix);
    check(false, { { 1, 2 }, { 3, 4 } }, { { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } }, { { { 9 } } }, { { {} } } }); // false
  }
  {
    auto check = solve_unordered(&Solution::unordered);
    check({ 7, 5, 3, 1, 4, 6, 9, 8, 2, 0 }, { 4, 6, 8, 0, 9, 1, 3, 5, 7, 2 }); // true
    check({ 7, 5, 3, 1, 4, 6, 9, 8, 2, 0 }, { 4, 6, 8, 0, 5, 1, 3, 5, 7, 2 }); // false
    check({ 7, 5, 3, 1, 4, 6, 9, 8, 2 }, { 4, 6, 8, 0, 9, 1, 3, 5, 7, 2 });    // false
  }
  return 0;
}

template <>
constexpr bool compare(Elem const & _Left, Elem const & _Right) {
  return _Left.v == _Right.v;
}
template <typename _Elem, typename _Traits>
constexpr basic_ostream<_Elem, _Traits> & write(basic_ostream<_Elem, _Traits> & _Ostr, Elem const & _Arg) {
  return _Ostr << "{v: " << _Arg.v << "}";
}

Settings;
