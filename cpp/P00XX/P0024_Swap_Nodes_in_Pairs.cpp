
#include "leetcode.hpp"

class Solution {
public:
  ListNode * swapPairs(ListNode * head) {
    if (head == nullptr) return head;
    auto p = &head;
    while (*p != nullptr && (*p)->next != nullptr) {
      auto q = &(*p)->next;
      auto t = *p;
      *p = *q;
      *q = (*p)->next;
      (*p)->next = t;
      p = q;
    }
    return head;
  }
};

int main() {
  {
    auto check = solve(&Solution::swapPairs);
    check({}, {});
    check({ 1 }, { 1 });
    check({ 2, 1 }, { 1, 2 });
    check({ 2, 1, 3 }, { 1, 2, 3 });
    check({ 2, 1, 4, 3 }, { 1, 2, 3, 4 });
  }
  return 0;
}

Settings;
