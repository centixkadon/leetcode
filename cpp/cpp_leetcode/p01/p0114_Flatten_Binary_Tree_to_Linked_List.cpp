
#include "leetcode.hpp"

class Solution {
public:
  void flatten(TreeNode * root) {
    flattenDfs(root);
  }

  TreeNode * flattenDfs(TreeNode * root) {
    if (root == nullptr) return nullptr;

    auto p = flattenDfs(root->left);
    auto q = flattenDfs(root->right);

    if (p) {
      p->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }

    if (q) return q;
    if (p) return p;
    return root;
  }

  TreeNode * flattenCheck(TreeNode * root) {
    flatten(root);
    return root;
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::flattenCheck);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check({}, {});
    check({ 1 }, { 1 });
    check({ 1, { {}, 2 } }, { 1, { 2 } });
    check({ 1, { {}, 3 } }, { 1, { {}, 3 } });
    check({ 1, { {}, { 2, { {}, 3 } } } }, { 1, { 2, 3 } });
    check({ 1, { {}, { 2, { {}, { 3, { {}, { 4, { {}, { 5, { {}, 6 } } } } } } } } } }, { 1, { { 2, { 3, 4 } }, { 5, { {}, 6 } } } });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
