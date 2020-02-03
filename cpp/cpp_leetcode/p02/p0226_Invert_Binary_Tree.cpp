
#include "leetcode.hpp"

class Solution {
public:
  TreeNode * invertTree(TreeNode * root) {
    if (root) tie(root->left, root->right) = make_tuple(invertTree(root->right), invertTree(root->left));
    return root;
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::invertTree);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check({}, {});
    check({ 1, { {}, 2 } }, { 1, { 2 } });
    check({ 1, { 3, 2 } }, { 1, { 2, 3 } });
    check({ 4, { { 7, { 9, 6 } }, { 2, { 3, 1 } } } }, { 4, { { 2, { 1, 3 } }, { 7, { 6, 9 } } } });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
