
#include "leetcode.hpp"

class Solution {
public:
  string longestCommonPrefix(vector<string> & strs) {
    if (strs.empty()) return "";

    size_t ans = 0;
    for (size_t i = 0; i != (size_t)-1; ++i) {
      char c = ' ';
      bool t = false;
      for (size_t j = 0; j < strs.size(); ++j) {
        if (i == strs[j].size()) {
          t = true;
          break;
        } else {
          if (c == ' ')
            c = strs[j][i];
          else if (c != strs[j][i]) {
            t = true;
            break;
          }
        }
      }
      if (t) {
        ans = i;
        break;
      }
    }

    return strs[0].substr(0, ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::longestCommonPrefix);
    check("", {});
    check("", { "", "" });
    check("a", { "a" });
    check("fl", { "flower", "flow", "flight" });
    check("", { "dog", "racecar", "car" });
  }
  return 0;
}

Settings;
