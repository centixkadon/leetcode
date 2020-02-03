
#include "leetcode.hpp"

class Solution {
public:
  int maxPathSum(TreeNode * root) {
    ans = numeric_limits<int>::min();
    maxPathSumDfs(root);
    return ans;
  }

  int maxPathSumDfs(TreeNode * root) {
    if (!root) return 0;

    int l = maxPathSumDfs(root->left), r = maxPathSumDfs(root->right);
    ans = max(ans, l + r + root->val);
    return max(root->val + max(l, r), 0);
  }

private:
  int ans;
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::maxPathSum);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check(1, { 1 });
    check(-1, { -1 });
    check(3, { 1, { 2 } });
    check(6, { 1, { 2, 3 } });
    check(42, { -10, { 9, { 20, { 15, 7 } } } });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
