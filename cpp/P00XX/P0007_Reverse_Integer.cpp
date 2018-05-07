
#include "leetcode.hpp"

class Solution {
public:
  int reverse(int x) {
    int const maxi = numeric_limits<int>::max(), mini = numeric_limits<int>::min();

    int ans = 0;
    while (x != 0) {
      if ((maxi / 10 < ans) || (ans < mini / 10)) return 0;
      ans *= 10;
      int k = x % 10;
      if (((k > 0) && (maxi - k < ans)) || ((k < 0) && (ans < mini - k))) return 0;
      ans += x % 10;
      x /= 10;
    }
    return ans;
  }
} s;

class TestCase {
public:
  TestCase() {
    cout << "P0007: Reverse Integer." << endl;

    auto && f = TestCase::testAnswer<int, int>;
    f(0, 0);
    f(1, 1);
    f(-1, -1);
    f(-1, -10);
    f(321, 123);
    f(-321, -123);
    f(21, 120);
    f(0, 1534236469);
    f(0, 2147483647);
    f(2147483641, 1463847412);
    f(0, 1563847412);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.reverse(const_cast<_Types &>(args)...);

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
