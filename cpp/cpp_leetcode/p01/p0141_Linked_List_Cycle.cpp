
#include "leetcode.hpp"

class Solution {
public:
  bool hasCycle(ListNode * head) {
    auto p = head, q = head;
    do {
      if (!q) return false;
      q = q->next;
      if (!q) return false;
      q = q->next;
      p = p->next;
    } while (p != q);
    return true;
  }

  bool hasCycleCheck(ListNode * head, int pos) {
    if (pos != -1) {
      auto p = head;
      for (int i = 0; i < pos; ++i) p = p->next;
      if (p) {
        auto q = p;
        while (q->next) q = q->next;
        q->next = p;
      }
    }
    return hasCycle(head);
  }
};

int main() {
  {
    auto check = solve(&Solution::hasCycleCheck);
    check(false, {}, -1);
    check(true, { 1 }, 0);
    check(false, { 1 }, -1);
    check(true, { 3, 2, 0, -4 }, 1);
    check(true, { 1, 2 }, 0);
  }
  return 0;
}

Settings;
