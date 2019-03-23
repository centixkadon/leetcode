
#include "leetcode.hpp"

class Solution {
public:
  string longestPalindrome(string s) {
    string ans = "";
    size_t n = s.size();
    for (size_t k = 0; k <= n; ++k) {
      {
        size_t i = k, j = k;
        while ((0 < i) && (j < n) && (s[i - 1] == s[j])) --i, ++j;
        if (j - i > ans.size()) ans = s.substr(i, j - i);
      }
      {
        size_t i = k, j = k + 1;
        while ((0 < i) && (j < n) && (s[i - 1] == s[j])) --i, ++j;
        if ((j <= n) && (j - i > ans.size())) ans = s.substr(i, j - i);
      }
    }
    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::longestPalindrome);
    check("", "");
    check("a", "a");
    check("a", "abcd");
    check("bab", "babad");
    check("bb", "cbbd");
  }
  return 0;
}

Settings;
