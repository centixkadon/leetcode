
#include "leetcode.hpp"

class Solution {
public:
  ListNode * sortList(ListNode * head) {
    auto h = new ListNode(0);
    h->next = head;

    auto p = h;
    size_t n = 0;
    while (p->next) {
      p = p->next;
      ++n;
    }

    for (size_t i = 1; i < n; i <<= 1) {
      sortListOnce(h, i);
    }

    head = h->next;
    delete h;
    h = nullptr;
    return head;
  }

  void sortListOnce(ListNode * head, size_t n) {
    while (head->next) {
      auto p = head, q = splitList(p, n), next = splitList(q, n);

      while (p->next && q->next) {
        if (p->next->val < q->next->val) {
          p = p->next;
        } else {
          auto t = q->next;
          q->next = t->next;
          t->next = p->next;
          p = p->next = t;
        }
      }
      if (q->next) {
        p->next = q->next;
      }
      delete q;

      while (p->next) p = p->next;
      p->next = next->next;
      head = p;
      delete next;
    }
  }

  ListNode * splitList(ListNode * head, size_t n) {
    auto p = head;
    for (size_t i = 0; i < n; ++i) {
      if (!p->next) break;
      p = p->next;
    }
    auto q = new ListNode(0);
    q->next = p->next;
    p->next = nullptr;
    return q;
  }
};

int main() {
  {
    auto check = solve(&Solution::sortList);
    check({}, {});
    check({ 4 }, { 4 });
    check({ 2, 4 }, { 4, 2 });
    check({ 1, 2, 4 }, { 4, 2, 1 });
    check({ 1, 2, 3, 4 }, { 4, 2, 1, 3 });
    check({ -1, 0, 3, 4, 5 }, { -1, 5, 3, 4, 0 });
  }
  return 0;
}

Settings;
