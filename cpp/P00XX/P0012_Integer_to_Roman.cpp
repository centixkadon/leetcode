
#include "leetcode.hpp"

class Solution {
public:
  string intToRoman(int num) {
    string r = "IVXLCDM";
    string ans = "";
    for (size_t i = 0; num != 0; ++i) {
      int k = num % 10;
      int p = (k + 1) / 5;
      int j = k - p * 5;
      string mid = "";
      if (p != 0) mid = r[i * 2 + p];
      ans = string(max(-j, 0), r[i * 2]) + mid + string(max(j, 0), r[i * 2]) + ans;

      num /= 10;
    }
    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::intToRoman);
    check("III", 3);
    check("IV", 4);
    check("IX", 9);
    check("LVIII", 58);
    check("MCMXCIV", 1994);
  }
  return 0;
}

Settings;
