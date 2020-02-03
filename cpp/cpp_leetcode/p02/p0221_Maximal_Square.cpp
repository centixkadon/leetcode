
#include "leetcode.hpp"

class Solution {
public:
  int maximalSquare(vector<vector<char>> & matrix) {
    if (matrix.empty()) return 0;
    if (matrix.front().empty()) return 0;

    size_t m = matrix.size(), n = matrix.front().size();
    vector<vector<int>> dp(m, vector<int>(n));

    int ans = 0;
    for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j) {
        if (matrix[i][j] == '0') {
          dp[i][j] = 0;
          continue;
        }
        if (i && j) {
          dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
        } else {
          dp[i][j] = 1;
        }
        ans = max(ans, dp[i][j]);
      }

    return ans * ans;
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::maximalSquare);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check(4, { "10100", "10111", "11111", "10010" });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
