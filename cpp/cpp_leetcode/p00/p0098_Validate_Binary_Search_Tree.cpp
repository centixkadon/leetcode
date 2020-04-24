
#include "leetcode.hpp"

class Solution {
public:
  bool isValidBST(TreeNode * root) {
    return get<0>(isValidBSTDfs(root));
  }

  tuple<bool, int, int> isValidBSTDfs(TreeNode * root) {
    if (root == nullptr) {
      return { true, numeric_limits<int>::max(), numeric_limits<int>::min() };
    }

    auto l = isValidBSTDfs(root->left);
    auto r = isValidBSTDfs(root->right);
    return { get<0>(l) && get<0>(r) && (get<2>(l) < get<1>(l) || get<2>(l) < root->val) && (get<2>(r) < get<1>(r) || root->val < get<1>(r)), min(get<1>(l), root->val), max(root->val, get<2>(r)) };
  }
};

int main() {
  {
    auto check = solve(&Solution::isValidBST);
    check(true, { 2147483647 });
    check(true, { 2, 1, 3 });
    check(false, { 1, { 1 } });
    check(false, { 5, 1, 4, {}, {}, 3, 6 });
  }
  return 0;
}

Settings;
