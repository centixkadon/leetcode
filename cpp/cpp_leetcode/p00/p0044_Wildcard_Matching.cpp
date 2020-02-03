
#include "leetcode.hpp"

class Solution {
public:
  uint8_t isMatchDfs(vector<vector<uint8_t>> & dp, string const & s, string const & p, size_t i = 0, size_t j = 0) {
    if (dp[i][j] != dp0) return dp[i][j];
    if (i == s.size() && j == p.size()) return dp[i][j] = dptrue;
    if (j == p.size() && i != s.size()) return dp[i][j] = dpfalse;

    if (p[j] == '*') {
      while (j < p.size() && p[j] == '*') ++j;
      for (size_t k = i; k <= s.size(); ++k)
        if (isMatchDfs(dp, s, p, k, j)) return dp[i][j] = dptrue;
    } else {
      while (i < s.size() && j < p.size() && (p[j] == '?' || p[j] == s[i])) {
        ++i;
        ++j;
      }
      if (j < p.size() && p[j] != '*') return dp[i][j] = dpfalse;
      if (isMatchDfs(dp, s, p, i, j)) return dp[i][j] = dptrue;
    }
    return dp[i][j] = dpfalse;
  }
  bool isMatch(string s, string p) {
    vector<vector<uint8_t>> dp(s.size() + 1, vector<uint8_t>(p.size() + 1, uint8_t(dp0)));
    return isMatchDfs(dp, s, p) == dptrue;
  }

private:
  static uint8_t const dp0 = numeric_limits<uint8_t>::max();
  static uint8_t const dptrue = 1;
  static uint8_t const dpfalse = 0;
};

int main() {
  {
    auto check = solve(&Solution::isMatch);
    check(false, "aa", "a");
    check(true, "aa", "*");
    check(false, "cb", "?a");
    check(true, "adceb", "*a*b");
    check(false, "acdcb", "a*c?b");
    check(true, "", "");
    check(true, "", "********************************************************************************************************************************");
    check(false, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", "********************************************************************************************************************************a");
    check(false, "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
  }
  return 0;
}

Settings;
