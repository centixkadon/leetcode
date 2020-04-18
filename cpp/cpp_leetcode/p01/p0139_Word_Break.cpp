
#include "leetcode.hpp"

class Solution {
public:
  bool wordBreak(string s, vector<string> & wordDict) {
    vector<bool> v(s.size() + 1, false);
    v[0] = true;
    for (size_t i = 1; i < v.size(); ++i) {
      for (auto & word : wordDict) {
        if (word.size() <= i && v[i - word.size()] && s.substr(i - word.size(), word.size()) == word) {
          v[i] = true;
          break;
        }
      }
    }
    return v[s.size()];
  }
};

int main() {
  {
    auto check = solve(&Solution::wordBreak);
    check(true, "leetcode", { "leet", "code" });
    check(true, "applepenapple", { "apple", "pen" });
    check(false, "catsandog", { "cats", "dog", "sand", "and", "cat" });
  }
  return 0;
}

Settings;
