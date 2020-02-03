
#include "leetcode.hpp"

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> map = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> ans = { "" };
    for (size_t i = 0; i < digits.size(); ++i) {
      vector<string> tmp;
      string & selects = map[digits[i] - '2'];
      for (auto & s : ans) {
        for (auto c : selects) {
          tmp.push_back(s + c);
        }
      }
      ans = move(tmp);
    }

    return move(ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::letterCombinations);
    check({}, "");
    check({ "a", "b", "c" }, "2");
    check({ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }, "23");
  }
  return 0;
}

Settings;
