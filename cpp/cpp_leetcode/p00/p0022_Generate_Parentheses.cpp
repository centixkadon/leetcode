
#include "leetcode.hpp"

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> ans(n + 1);
    for (size_t j = 1; j < ans.size(); ++j) ans[j] = { string(j, '(') };
    for (size_t i = 1; i < ans.size(); ++i) {
      for (size_t j = 1; j < ans.size(); ++j) {
        if (i > j) {
          ans[j] = {};
        } else {
          for (size_t k = 0; k < ans[j].size(); ++k) ans[j][k] += ')';
          for (size_t k = 0; k < ans[j - 1].size(); ++k) ans[j].push_back(ans[j - 1][k] + '(');
        }
      }
    }
    return move(ans[n]);
  }
};

int main() {
  {
    auto check = solve_unordered(&Solution::generateParenthesis);
    check({}, 0);
    check({ "()" }, 1);
    check({ "()()", "(())" }, 2);
    check({ "((()))", "(()())", "(())()", "()(())", "()()()" }, 3);
  }
  return 0;
}

Settings;
