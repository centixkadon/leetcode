
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

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0019: Remove Nth Node From End of List." << endl;

    auto && f = testAnswer<ListNode *, ListNode *, int>;
    f(vtol({}), vtol({ 1 }), 1);
    f(vtol({ 1, 2, 3, 4 }), vtol({ 1, 2, 3, 4, 5 }), 1);
    f(vtol({ 2, 3, 4, 5 }), vtol({ 1, 2, 3, 4, 5 }), 5);
    f(vtol({ 1, 2, 3, 5 }), vtol({ 1, 2, 3, 4, 5 }), 2);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  static bool compareAnswer(ListNode const * l, ListNode const * r) {
    while ((l != NULL) && (r != NULL)) {
      if (l->val != r->val) return false;
      l = l->next;
      r = r->next;
    }
    if ((l != NULL) || (r != NULL)) return false;
    return true;
  }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.removeNthFromEnd(const_cast<_Types &>(args)...);

    ++Q;
    if (!compareAnswer(ans, _ans)) {
      printParameterPacks(cout << Q << " Q: ", args...) << endl;
      cout << Q << " O: " << ans << endl;
      cout << Q << " X: " << _ans << endl;
      ++X;
    }
  }
};

int main() {
  TestCase();

  return 0;
}
