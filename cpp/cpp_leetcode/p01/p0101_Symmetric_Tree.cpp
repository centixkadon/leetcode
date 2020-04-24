
#include "leetcode.hpp"

class Solution {
public:
  bool isSymmetric(TreeNode * root) {
    if (root == nullptr) return true;

    deque<TreeNode *> l, r;
    l.push_back(root);
    r.push_back(root);
    while (!l.empty() && !r.empty()) {
      auto p = l.front(), q = r.front();
      l.pop_front();
      r.pop_front();
      if (p->val != q->val) return false;

      if (p->left && q->right) {
        l.push_back(p->left);
        r.push_back(q->right);
      } else if (p->left || q->right) {
        return false;
      }

      if (p->right && q->left) {
        l.push_back(p->right);
        r.push_back(q->left);
      } else if (p->right || q->left) {
        return false;
      }
    }

    return l.empty() && r.empty();
  }
};

int main() {
  {
    auto check = solve(&Solution::isSymmetric);
    check(true, { 1, 2, 2, 3, 4, 4, 3 });
    check(false, { 1, 2, 2, {}, 3, {}, 3 });
  }
  return 0;
}

Settings;
