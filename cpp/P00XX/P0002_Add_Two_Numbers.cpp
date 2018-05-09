
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

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0002: Add Two Numbers." << endl;

    auto && f = testAnswer<ListNode *, ListNode *, ListNode *>;
    f(itol(0), itol(0), itol(0));
    f(itol(10), itol(10), itol(0));
    f(itol(10), itol(0), itol(10));
    f(itol(20), itol(10), itol(10));
    f(itol(1998), itol(999), itol(999));

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
    _Ans && _ans = s.addTwoNumbers(const_cast<_Types &>(args)...);

    ++Q;
    if (!compareAnswer(ans, _ans)) {
      printParameterPacks(cout << Q << " Q: ", args...) << endl;
      cout << Q << " O: " << ans << endl;
      cout << Q << " X: " << _ans << endl;
      ++X;
    }
  }

  static ListNode * itol(int i) {
    string s = move(static_cast<stringstream &>(stringstream() << i).str());
    ListNode * h = NULL;
    for (auto c : s) {
      auto p = h;
      h = new ListNode(c - '0');
      h->next = p;
    }
    return h;
  }
};

int main() {
  TestCase();

  return 0;
}
