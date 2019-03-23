
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
};

int main() {
  {
    auto check = solve(&Solution::reverse);
    check(0, 0);
    check(1, 1);
    check(-1, -1);
    check(-1, -10);
    check(321, 123);
    check(-321, -123);
    check(21, 120);
    check(0, 1534236469);
    check(0, 2147483647);
    check(2147483641, 1463847412);
    check(0, 1563847412);
  }
  return 0;
}

Settings;
