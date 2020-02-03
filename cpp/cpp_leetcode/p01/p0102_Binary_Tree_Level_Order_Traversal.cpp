
#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode * root) {
    vector<vector<int>> ans;
    levelOrderDfs(ans, root, 0);
    return move(ans);
  }

  void levelOrderDfs(vector<vector<int>> & ans, TreeNode * p, size_t d) {
    if (p == nullptr) return;

    if (ans.size() < d + 1) ans.resize(d + 1);
    ans[d].push_back(p->val);
    levelOrderDfs(ans, p->left, d + 1);
    levelOrderDfs(ans, p->right, d + 1);
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::levelOrder);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check({}, {});
    check({ { 1 } }, { 1 });
    check({ { 3 }, { 9, 20 }, { 15, 7 } }, { 3, { 9, { 20, { 15, 7 } } } });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
