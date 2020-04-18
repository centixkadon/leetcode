
#include "leetcode.hpp"

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> & wordDict) {
    vector<string> ans;
    vector<string const *> wordStack;
    wordStack.reserve(s.size());
    vector<bool> invalids(s.size() + 1, false);

    wordBreakDfs(ans, wordStack, invalids, s, wordDict);
    for (auto & s : ans) cout << '"' << s << '"' << endl;
    return move(ans);
  }

  void wordBreakDfs(vector<string> & ans, vector<string const *> & wordStack, vector<bool> & invalids, string const & s, vector<string> const & words, size_t index = 0) {
    if (index == s.size()) {
      string str;
      for (auto wordPtr : wordStack) {
        str += *wordPtr;
        str += " ";
      }
      str.pop_back();

      ans.emplace_back(move(str));
      return;
    }

    if (invalids[index]) return;

    size_t ansSize = ans.size();
    for (auto const & word : words) {
      if (index + word.size() <= s.size() && s.compare(index, word.size(), word) == 0) {
        wordStack.push_back(&word);
        wordBreakDfs(ans, wordStack, invalids, s, words, index + word.size());
        wordStack.pop_back();
      }
    }

    invalids[index] = ansSize == ans.size();
  }
};

int main() {
  {
    auto check = solve_unordered(&Solution::wordBreak);
    check({ "leet code" }, "leetcode", { "leet", "code" });
    check({ "cats and dog", "cat sand dog" }, "catsanddog", { "cat", "cats", "and", "sand", "dog" });
    check({ "pine apple pen apple", "pineapple pen apple", "pine applepen apple" }, "pineapplepenapple", { "apple", "pen", "applepen", "pine", "pineapple" });
    check({}, "catsandog", { "cats", "dog", "sand", "and", "cat" });
  }
  return 0;
}

Settings;
