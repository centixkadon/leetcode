
#include "leetcode.hpp"

class Solution {
public:
  double myPow(double x, int n) {
    if (n < 0) {
      x = 1.0 / x;
      if (n != numeric_limits<int>::min()) n = -n;
    }

    double ans = 1.0;
    for (int i = 31; i >= 0; --i) {
      ans *= ans;
      if (n & (1 << i)) ans *= x;
    }

    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::myPow);
    check(1024.0, 2.0, 10);
    check(9.261, 2.1, 3);
    check(0.25, 2.0, -2);
    check(0.0, 2.0, numeric_limits<int>::min());
    check(numeric_limits<double>::infinity(), 2.0, numeric_limits<int>::max());
  }
  return 0;
}

Settings;
