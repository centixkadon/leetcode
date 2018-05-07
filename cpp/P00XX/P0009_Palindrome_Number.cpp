
#include "leetcode.hpp"

class Solution {
public:
  bool isPalindrome(int x) {
    if ((x < 0) || ((x % 10 == 0) && (x != 0))) return false;
    int ans = 0;
    while (x > ans) {
      ans = ans * 10 + x % 10;
      x /= 10;
    }
    return (x == ans) || (x == ans / 10);
  }
} s;

class TestCase {
public:
  TestCase() {
    cout << "P0009: Palindrome Number." << endl;

    auto && f = TestCase::testAnswer<bool, int>;
    f(false, -121);
    f(false, 10);
    f(true, 121);
    f(true, 1221);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.isPalindrome(const_cast<_Types &>(args)...);

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
