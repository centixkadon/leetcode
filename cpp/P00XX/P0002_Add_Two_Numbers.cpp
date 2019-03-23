
#include "leetcode.hpp"

class Solution {
public:
  ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
    int k = 0;
    ListNode * h = NULL;
    ListNode ** e = &h;
    while ((l1 != NULL) || (l2 != NULL) || (k != 0)) {
      if (l1 != NULL) {
        k += l1->val;
        l1 = l1->next;
      }
      if (l2 != NULL) {
        k += l2->val;
        l2 = l2->next;
      }
      ListNode * p = new ListNode(k % 10);
      *e = p;
      e = &p->next;
      k /= 10;
    }
    return h;
  }
};

int main() {
  {
    auto check = solve(&Solution::addTwoNumbers);
    check({ 0 }, { 0 }, { 0 });
    check({ 0, 1 }, { 0, 1 }, { 0 });
    check({ 0, 1 }, { 0 }, { 0, 1 });
    check({ 0, 2 }, { 0, 1 }, { 0, 1 });
    check({ 8, 9, 9, 1 }, { 9, 9, 9 }, { 9, 9, 9 });
  }
  return 0;
}

Settings;
