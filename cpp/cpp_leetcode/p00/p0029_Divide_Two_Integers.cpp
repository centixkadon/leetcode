
#include "leetcode.hpp"

class Solution {
public:
  static int const imin = numeric_limits<int>::min();
  static int const imax = numeric_limits<int>::max();
  int divide(int dividend, int divisor) {
    if (divisor == imin) return (dividend == imin) ? 1 : 0;

    bool t = false;
    if (divisor < 0) {
      divisor = -divisor;
      t = !t;
    }
    int k = 0;
    if (dividend < 0) {
      dividend = -(dividend + 1);
      k = 1;
      t = !t;
    }

    int i = 0;
    for (; i < 30; ++i) {
      if ((divisor << (i + 1)) <= 0) break;
      if (dividend < (divisor << (i + 1))) break;
    }

    int ans = 0;
    for (; i >= 0; --i) {
      if (dividend >= (divisor << i)) {
        dividend -= divisor << i;
        ans |= 1 << i;
      }
    }
    if (t) ans = -ans;

    dividend += k;
    if (dividend >= divisor) {
      if (t)
        ans -= 1;
      else if (ans < imax)
        ans += 1;
    }

    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::divide);
    check(3, 10, 3);
    check(-3, 10, -3);
    check(-3, -10, 3);
    check(3, -10, -3);
    check(2, 10, 5);
    check(-2, 10, -5);
    check(-2, -10, 5);
    check(2, -10, -5);
    check(numeric_limits<int>::max(), numeric_limits<int>::max(), 1);
    check(-numeric_limits<int>::max(), numeric_limits<int>::max(), -1);
    check(numeric_limits<int>::min(), numeric_limits<int>::min(), 1);
    check(numeric_limits<int>::max(), numeric_limits<int>::min(), -1);
    check(1, numeric_limits<int>::max(), numeric_limits<int>::max());
    check(0, numeric_limits<int>::max(), numeric_limits<int>::min());
    check(-1, numeric_limits<int>::min(), numeric_limits<int>::max());
    check(1, numeric_limits<int>::min(), numeric_limits<int>::min());
  }
  return 0;
}

Settings;
