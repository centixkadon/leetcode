
#include "leetcode.hpp"

class Solution {
public:
  TreeNode * invertTree(TreeNode * root) {
    if (root) tie(root->left, root->right) = make_tuple(invertTree(root->right), invertTree(root->left));
    return root;
  }
};

int main() {
  {
    auto check = solve(&Solution::invertTree);
    check({}, {});
    check({ 1, {}, 2 }, { 1, 2 });
    check({ 1, 3, 2 }, { 1, 2, 3 });
    check({ 4, 7, 2, 9, 6, 3, 1 }, { 4, 2, 7, 1, 3, 6, 9 });
  }
  return 0;
}

Settings;
