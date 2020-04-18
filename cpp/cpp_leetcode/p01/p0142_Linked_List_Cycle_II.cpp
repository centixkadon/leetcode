
#include "leetcode.hpp"

class Solution {
public:
  ListNode * detectCycle(ListNode * head) {
    auto p = head, q = head;
    do {
      if (!q) return nullptr;
      q = q->next;
      if (!q) return nullptr;
      q = q->next;
      p = p->next;
    } while (p != q);

    p = head;
    while (p != q) {
      p = p->next;
      q = q->next;
    }
    return p;
  }

  int detectCycleCheck(ListNode * head, int pos) {
    if (pos != -1) {
      auto p = head;
      for (int i = 0; i < pos; ++i) p = p->next;
      if (p) {
        auto q = p;
        while (q->next) q = q->next;
        q->next = p;
      }
    }
    auto ans = detectCycle(head);
    return ans ? ans->val : -1;
  }
};

int main() {
  {
    auto check = solve(&Solution::detectCycleCheck);
    check(-1, {}, -1);
    check(1, { 1 }, 0);
    check(-1, { 1 }, -1);
    check(2, { 3, 2, 0, -4 }, 1);
    check(1, { 1, 2 }, 0);
  }
  return 0;
}

Settings;
