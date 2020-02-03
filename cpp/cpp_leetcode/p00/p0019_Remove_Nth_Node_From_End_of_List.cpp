
#include "leetcode.hpp"

class Solution {
public:
  ListNode * removeNthFromEnd(ListNode * head, int n) {
    auto p = head;
    auto q = &head;
    for (int i = 0; i < n; ++i) p = p->next;
    while (p != NULL) {
      q = &(*q)->next;
      p = p->next;
    }
    p = *q;
    *q = p->next;
    delete p;
    return head;
  }
};

int main() {
  {
    auto check = solve(&Solution::removeNthFromEnd);
    check({}, { 1 }, 1);
    check({ 1, 2, 3, 4 }, { 1, 2, 3, 4, 5 }, 1);
    check({ 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, 5);
    check({ 1, 2, 3, 5 }, { 1, 2, 3, 4, 5 }, 2);
  }
  return 0;
}

Settings;
