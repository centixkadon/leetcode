
#include "leetcode.hpp"

class Solution {
public:
  string minWindow(string s, string t) {
    vector<ptrdiff_t> v(numeric_limits<make_unsigned_t<string::value_type>>::max(), 0);
    for (auto c : t) ++v[c];

    size_t i = 0, cnt = t.size();
    size_t off = 0, count = string::npos;
    for (size_t j = 0; j < s.size(); ++j) {
      auto c = s[j];
      --v[c];
      if (v[c] >= 0) { --cnt; }
      while (cnt == 0) {
        if (j - i + 1 < count) {
          off = i;
          count = j - i + 1;
        }
        c = s[i];
        ++v[c];
        if (v[c] > 0) { ++cnt; }
        ++i;
      }
    }

    return count == string::npos ? "" : s.substr(off, count);
  }
};

int main() {
  {
    auto check = solve(&Solution::minWindow);
    check("BANC", "ADOBECODEBANC", "ABC");
    check("", "", "");
    check("", "ADOBECODEBANC", "");
    check("", "", "A");
    check("A", "ADOBECODEBANC", "A");
  }
  return 0;
}

Settings;
