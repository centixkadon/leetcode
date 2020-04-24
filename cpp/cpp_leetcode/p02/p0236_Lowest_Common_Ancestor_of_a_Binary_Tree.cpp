
#include "leetcode.hpp"

class Solution {
public:
  bool lowestCommonAncestorDfs(TreeNode * root, TreeNode * p, TreeNode * q) {
    if (!root) return false;
    size_t sum = 0;
    if (lowestCommonAncestorDfs(root->left, p, q)) ++sum;
    if (lowestCommonAncestorDfs(root->right, p, q)) ++sum;
    if (root == p || root == q) ++sum;
    if (sum == 2) ans = root;
    return sum != 0;
  }

  TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
    ans = nullptr;
    lowestCommonAncestorDfs(root, p, q);
    return ans;
  }

  int lowestCommonAncestorTest(TreeNode * root, vector<bool> tp, vector<bool> tq) {
    auto p = root, q = root;
    for (auto t : tp) p = t ? p->right : p->left;
    for (auto t : tq) q = t ? q->right : q->left;

    auto r = lowestCommonAncestor(root, p, q);
    return r ? r->val : -1;
  }

private:
  TreeNode * ans;
};

int main() {
  {
    auto check = solve(&Solution::lowestCommonAncestorTest);
    check(3, { 3, 5, 1, 6, 2, 0, 8, {}, {}, 7, 4 }, { false }, { true });
    check(5, { 3, 5, 1, 6, 2, 0, 8, {}, {}, 7, 4 }, { false }, { false, true, true });
  }
  return 0;
}

Settings;
