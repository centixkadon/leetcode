
#include "leetcode.hpp"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<bool> m(256);
    for (int c = 0; c < 256; ++c) m[c] = true;

    size_t ans = 0;
    size_t j = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (m[c]) {
        m[c] = false;
      } else {
        while (s[j] != c) {
          m[s[j]] = true;
          ++j;
        }
        ++j;
      }
      if (i - j + 1 > ans) ans = i - j + 1;
    }
    return static_cast<int>(ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::lengthOfLongestSubstring);
    check(3, "abcabcbb");
    check(1, "bbbbb");
    check(3, "pwwkew");
    check(1, "a");
    check(0, "");
  }
  return 0;
}

Settings;
