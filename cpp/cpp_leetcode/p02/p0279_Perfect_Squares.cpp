
#include "leetcode.hpp"

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (size_t i = 1; i < dp.size(); ++i) {
      dp[i] = dp[i - 1];
      for (size_t j = 2; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j]);
      }
      ++dp[i];
    }

    return dp[n];
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::numSquares);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check(3, 12);
    check(2, 13);
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
