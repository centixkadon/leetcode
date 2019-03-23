
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
};

int main() {
  {
    auto check = solve(&Solution::isPalindrome);
    check(false, -121);
    check(false, 10);
    check(true, 121);
    check(true, 1221);
  }
  return 0;
}

Settings;
