
#include "leetcode.hpp"

class Solution {
public:
  ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
    ListNode * h = NULL;
    auto p = &h;
    while ((l1 != NULL) || (l2 != NULL)) {
      if (l2 == NULL) {
        *p = l1;
        l1 = l1->next;
      } else if (l1 == NULL) {
        *p = l2;
        l2 = l2->next;
      } else if (l1->val <= l2->val) {
        *p = l1;
        l1 = l1->next;
      } else {
        *p = l2;
        l2 = l2->next;
      }
      p = &(*p)->next;
    }
    return h;
  }
};

int main() {
  {
    auto check = solve(&Solution::mergeTwoLists);
    check({}, {}, {});
    check({ 1 }, { 1 }, {});
    check({ 2 }, {}, { 2 });
    check({ 1, 2 }, { 1 }, { 2 });
    check({ 1, 1, 2, 3, 4, 4 }, { 1, 2, 4 }, { 1, 3, 4 });
  }
  return 0;
}

Settings;
