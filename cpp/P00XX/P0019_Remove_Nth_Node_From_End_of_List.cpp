
#include "leetcode.hpp"

struct ListNode {
  int val;
  ListNode * next;
  ListNode(int x) : val(x), next(NULL) {}
};

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

template <typename _Elem, typename _Traits>
basic_ostream<_Elem, _Traits> & operator<<(basic_ostream<_Elem, _Traits> & _Ostr, ListNode const * _Right) {
  _Ostr << "[ ";
  while (_Right != NULL) {
    _Ostr << " -> " << _Right->val;
    _Right = _Right->next;
  }
  return _Ostr << " ]";
}

class TestCase {
public:
  TestCase() {
    cout << "P0019: Remove Nth Node From End of List." << endl;

    auto && f = testAnswer<ListNode *, ListNode *, int>;
    f(vtol({}), vtol({ 1 }), 1);
    f(vtol({ 4, 3, 2, 1 }), vtol({ 5, 4, 3, 2, 1 }), 1);
    f(vtol({ 5, 4, 3, 2 }), vtol({ 5, 4, 3, 2, 1 }), 5);
    f(vtol({ 5, 3, 2, 1 }), vtol({ 5, 4, 3, 2, 1 }), 2);

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

  static ListNode * vtol(vector<int> const & v) {
    ListNode * h = NULL;
    for (auto elem : v) {
      auto p = h;
      h = new ListNode(elem);
      h->next = p;
    }
    return h;
  }
};

int main() {
  TestCase();

  return 0;
}
