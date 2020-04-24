
#include "leetcode.hpp"

struct Elem {
  int a, b;
};

class Solution {
public:
  int add(int a, int b) { return a + b; }

  int debug(int value) {
    cerr << "debug: " << value << endl;
    return value;
  }

  int struct_elem(Elem const & e) { return e.a * e.b; }

  size_t vector_size(vector<int> v1, vector<int> & v2, vector<int> const & v3) { return v1.size() + v2.size() + v3.size(); }

  ListNode * slice_list(ListNode * l) {
    if (l == nullptr) return l;
    return l->next;
  }

  TreeNode * left_tree(TreeNode * t) {
    if (t == nullptr) return t;
    return t->left;
  }

  vector<size_t> unordered(vector<size_t> & v) { return v; }

  size_t mix_list_tree(TreeNode_<vector<size_t>> * t, ListNode_<vector<ListNode_<vector<size_t>> *>> * l) {
    size_t ans = 0;
    while (t) {
      ans += t->val.size();
      t = t->left;
    }
    while (l) {
      for (auto p : l->val) {
        while (p) {
          for (auto e : p->val) ans += e;
          p = p->next;
        }
      }
      l = l->next;
    }
    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::add);
    check(0, 0, 0);
    check(1, 1, 0);
    check(2, 0, 2);
    check(0, -3, 3);
    check(-1, 4, -5);
  }
  {
    auto check = solve(&Solution::debug);
    check(0, 0);
    check(1, 1);
    check.debug(2, 2);
    check(3, 3);
    check(4, 4);
  }
  {
    auto check = solve(&Solution::struct_elem);
    check(0, { 0, 0 });
    check(0, { 1, 0 });
    check(4, { 2, 2 });
    check(-12, { -3, 4 });
    check(30, { -5, -6 });
  }
  {
    auto check = solve(&Solution::vector_size);
    check(0, {}, {}, {});
    check(1, { 1 }, {}, {});
    check(1, {}, { 2 }, {});
    check(1, {}, {}, { 3 });
    check(6, { 1 }, { 2, 3 }, { 4, 5, 6 });
  }
  {
    auto check = solve(&Solution::slice_list);
    check({}, {});
    check({}, { 1 });
    check({ 2 }, { 1, 2 });
    check({ 2, 3 }, { 1, 2, 3 });
    check({ 5, 3, 1, 4, 6, 9, 8, 2, 0 }, { 7, 5, 3, 1, 4, 6, 9, 8, 2, 0 });
  }
  {
    auto check = solve(&Solution::left_tree);
    check({}, {});
    check({}, { 1 });
    check({ 2, 4, 5, 8, 9 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    check({ 2, 4, {}, 8 }, { 1, 2, 3, 4, {}, {}, 7, 8, {} });
    check({ 2, {}, 5, 8, 9 }, { 1, 2, 3, {}, 5, 6, 7, 8, 9 });
  }
  {
    auto check = solve_unordered(&Solution::unordered);
    check({}, {});
    check({ 1 }, { 1 });
    check({ 1, 2, 3 }, { 3, 2, 1 });
    check({ 7, 5, 3, 1, 4, 6, 9, 8, 2 }, { 4, 6, 8, 9, 1, 3, 5, 7, 2 });
    check({ 7, 5, 3, 1, 4, 6, 9, 8, 2, 0 }, { 4, 6, 8, 0, 9, 1, 3, 5, 7, 2 });
  }
  {
    auto check = solve(&Solution::mix_list_tree);
    check(0, {}, {});
    check(3, { { { 1 } }, { { 2 } }, { { 3 } } }, { { { { 1 } } } });
    check(5, { { { 1 } }, { { 2 } }, { { 3 } }, { { 4 } }, {}, {}, { { 7 } }, { { 8 } }, {} }, { { { { 1 } } } });
    check(9, { { {} }, {}, { { 1, 2, 3, 4, 5, 6, 7, 8, 9 } } }, { { { { 9 } } } });
    check(45, { {} }, { { { { 1, 2, 3 }, { 4 }, {} }, { { 5 }, { 6 }, { 7 }, { 8 } } }, { { { 9 } } }, { { {} } } });
  }
  return 0;
}

template <>
constexpr bool compare(Elem const & _Left, Elem const & _Right) {
  return _Left.a == _Right.a && _Left.b == _Right.b;
}
template <typename _Elem, typename _Traits>
constexpr basic_ostream<_Elem, _Traits> & write(basic_ostream<_Elem, _Traits> & _Ostr, Elem const & _Arg) {
  return write(write(_Ostr << "{a=", _Arg.a) << ",b=", _Arg.b) << "}";
}

Settings;
