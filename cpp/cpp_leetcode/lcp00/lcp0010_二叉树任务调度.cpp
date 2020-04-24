
#include "leetcode.hpp"

class Solution {
public:
  pair<int, int> minimalExecTimeDfs(TreeNode * root) {
    if (root == nullptr) return { 0, 0 };

    auto l = minimalExecTimeDfs(root->left);
    auto r = minimalExecTimeDfs(root->right);

    auto c = min(l.first, r.first);
    l.first -= c;
    r.first -= c;
    auto tmp = c + c; // add to second

    auto a = min(l.second, r.first);
    r.first -= a;
    l.second += a;

    auto b = min(l.first, r.second);
    l.first -= b;
    r.second += b;

    return { l.first + r.first + root->val, l.second + r.second + tmp };
  }

  double minimalExecTime(TreeNode * root) {
    auto ans = minimalExecTimeDfs(root);
    return ans.first + ans.second * 0.5;
  }
};

int main() {
  {
    auto check = solve(&Solution::minimalExecTime);
    check(121, { 47, 74, 31 });
    check(87, { 15, 21, {}, 24, {}, 27, 26 });
    check(7.5, { 1, 3, 2, {}, {}, 4, 4 });
  }
  return 0;
}

Settings;
