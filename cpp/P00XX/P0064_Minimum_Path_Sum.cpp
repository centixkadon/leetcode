
#include "leetcode.hpp"

class Solution {
public:
  int minPathSum(vector<vector<int>> & grid) {
    auto dp = grid;
    for (size_t i = 0; i < grid.size(); ++i)
      for (size_t j = 0; j < grid[i].size(); ++j) {
        int k = numeric_limits<int>::max();
        if (i == 0 && j == 0) k = 0;
        if (i > 0) k = min(k, dp[i - 1][j]);
        if (j > 0) k = min(k, dp[i][j - 1]);
        dp[i][j] = grid[i][j] + k;
      }
    return dp.back().back();
  }
};

int main() {
  {
    auto check = solve(&Solution::minPathSum);
    check(0, { { 0 } });
    check(1, { { 1 } });
    check(7, { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } });
  }
  return 0;
}

Settings;
