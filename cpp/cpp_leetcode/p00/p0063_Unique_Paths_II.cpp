
#include "leetcode.hpp"

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid) {
    auto dp = obstacleGrid;
    for (size_t i = 0; i < obstacleGrid.size(); ++i)
      for (size_t j = 0; j < obstacleGrid[i].size(); ++j) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
          continue;
        }
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
          continue;
        }
        int k = 0;
        if (i > 0 && j < obstacleGrid[i - 1].size()) k += dp[i - 1][j];
        if (j > 0) k += min(dp[i][j - 1], numeric_limits<int>::max() - k);
        dp[i][j] = k;
      }
    return dp.back().back();
  }
};

int main() {
  {
    auto check = solve(&Solution::uniquePathsWithObstacles);
    check(0, { { 1 } });
    check(1, { { 0 } });
    check(2, { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } });
  }
  return 0;
}

Settings;
