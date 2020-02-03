
#include "leetcode.hpp"

class Solution {
public:
  int myAtoi(string str) {
    int const maxi = numeric_limits<int>::max(), mini = numeric_limits<int>::min();

    bool minus = false;
    string numerical = "0123456789";
    size_t i = string::npos, j = str.size();
    for (size_t k = str.find_first_not_of(' '); k < str.size(); ++k) {
      if ((str[k] == '+') || (str[k] == '-')) {
        minus = str[k] == '-';
        ++k;
        if (k == str.size()) break;
      }

      if (numerical.find(str[k]) != string::npos) i = k;
      break;
    }
    if (i == string::npos) return 0;
    for (size_t k = i + 1; k < str.size(); ++k) {
      if (numerical.find(str[k]) == string::npos) {
        j = k;
        break;
      }
    }

    string s = str.substr(i, j - i);
    int ans = 0;
    for (auto c : s) {
      if (ans > maxi / 10) return maxi;
      if (ans < mini / 10) return mini;
      ans *= 10;

      int k = c - '0';
      if (minus) {
        if (ans < mini + k) return mini;
        ans -= k;
      } else {
        if (ans > maxi - k) return maxi;
        ans += k;
      }
    }
    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::myAtoi);
    check(0, "words and 987");
    check(0, "");
    check(0, "-");
    check(0, "-0");
    check(0, "-00");
    check(-1, "-001");
    check(-1, "-001-1111");
    check(-9, "-9");
    check(0, "+-2");
    check(9, "9");
    check(42, "42");
    check(-42, "   -42");
    check(4193, "4193 with words");
    check(-2147483648, "-2147483649");
    check(2147483647, "2147483648");
    check(-2147483648, "-91283472332");
    check(2147483647, "91283472332");
  }
  return 0;
}

Settings;
