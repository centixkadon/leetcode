
#include "leetcode.hpp"

class Solution {
public:
  ListNode * reverseKGroup(ListNode * head, int k) {
    ListNode h(0);
    auto p = &h;
    p->next = head;

    while (p != nullptr) {
      bool t = true;
      auto q = p;
      for (int i = 0; i < k; ++i) {
        q = q->next;
        if (q == nullptr) {
          t = false;
          break;
        }
      }
      if (t) {
        auto tail = q->next;
        auto nextp = p->next;
        for (int i = 0; i < k - 1; ++i) {
          auto tmp = p->next->next;
          p->next->next = tail;
          tail = p->next;
          p->next = tmp;
        }
        p->next->next = tail;
        p = nextp;
      } else {
        break;
      }
    }
    return h.next;
  }
};

int main() {
  {
    auto check = solve(&Solution::reverseKGroup);
    check({}, {}, 2);
    check({ 1 }, { 1 }, 2);
    check({ 2, 1 }, { 1, 2 }, 2);
    check({ 2, 1, 3 }, { 1, 2, 3 }, 2);
    check({ 2, 1, 4, 3 }, { 1, 2, 3, 4 }, 2);
    check({ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, 1);
    check({ 2, 1, 4, 3, 5 }, { 1, 2, 3, 4, 5 }, 2);
    check({ 3, 2, 1, 4, 5 }, { 1, 2, 3, 4, 5 }, 3);
  }
  return 0;
}

Settings;
