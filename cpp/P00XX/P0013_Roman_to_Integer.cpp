
#include "leetcode.hpp"

class Solution {
public:
  int romanToInt(string s) {
    map<char, int> m = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
    int ans = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if ((i + 1 < s.size()) && (m[s[i]] < m[s[i + 1]]))
        ans -= m[s[i]];
      else
        ans += m[s[i]];
    }
    return ans;
  }

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
    auto check = solve(&Solution::romanToInt);
    for (int i = 0; i < 4000; ++i) check(static_cast<int const>(i), Solution().intToRoman(i));
  }
  return 0;
}

Settings;
