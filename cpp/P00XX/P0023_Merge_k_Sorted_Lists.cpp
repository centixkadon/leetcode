
#include "leetcode.hpp"

class Solution {
public:
  ListNode * mergeKLists(vector<ListNode *> & lists) {
    struct ListElem {
      ListNode * p;
      int v;

      typedef ListElem _Myt;
      ListElem(ListNode * _p) : p(_p), v(_p->val) {}
      bool operator<(_Myt const & _Right) const { return v >= _Right.v; }
    };

    priority_queue<ListElem> l;
    for (auto list : lists) {
      if (list != NULL) l.push(list);
    }

    ListNode * h = NULL;
    auto p = &h;
    while (!l.empty()) {
      auto q = l.top().p;
      l.pop();
      *p = q;
      p = &q->next;
      if (*p != NULL) { l.push(*p); };
    }

    return h;
  }
};

int main() {
  {
    auto check = solve(&Solution::mergeKLists);
    check({}, { {}, {} });
    check({ 1 }, { { 1 }, {} });
    check({ 2 }, { {}, { 2 } });
    check({ 3 }, { {}, { 3 }, {} });
    check({ 1, 2 }, { { 1 }, { 2 } });
    check({ 1, 1, 2, 3, 4, 4, 5, 6 }, { { 1, 4, 5 }, { 1, 3, 4 }, { 2, 6 } });
  }
  return 0;
}

Settings;
