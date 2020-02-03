
#include "leetcode.hpp"

class Solution {
public:
  vector<int> inorderTraversal(TreeNode * root) {
    vector<int> ans;
    stack<TreeNode *> nodes;
    while (!nodes.empty() || root) {
      while (root) {
        nodes.push(root);
        root = root->left;
      }
      root = nodes.top();
      nodes.pop();
      ans.push_back(root->val);
      root = root->right;
    }

    return move(ans);
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::inorderTraversal);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check({}, {});
    check({ 1 }, { 1 });
    check({ 1, 3, 2 }, { 1, { {}, { 2, { 3 } } } });
    check({ 1, 2, 3, 4, 5, 6, 7 }, { 4, { { 2, { 1, 3 } }, { 6, { 5, 7 } } } });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;