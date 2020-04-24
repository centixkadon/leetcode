
#include "leetcode.hpp"

class Solution {
public:
  int numOfArrays(int n, int m, int k) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(m, 0)));
    for (int kk = 0; kk < k; ++kk) {
      for (int j = 0; j < m; ++j) {
        dp[0][kk][j] = kk == 0 ? 1 : 0;
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int kk = 0; kk < k; ++kk) {
        int tmp = 0;
        for (int j = 0; j < m; ++j) {
          int f = 0;
          f = (f + int(size_t(dp[i - 1][kk][j]) * (j + 1) % mod)) % mod;
          if (kk) {
            f = (f + tmp) % mod;
            if (j < m) tmp = (tmp + dp[i - 1][kk - 1][j]) % mod;
          }
          dp[i][kk][j] = f;
        }
      }
    }

    int ans = 0;
    for (int a = 0; a < m; ++a) ans = (ans + dp.back().back()[a]) % mod;
    return ans;
  }

  static int const mod = 1000000007;
};

int main() {
  {
    auto check = solve(&Solution::numOfArrays);
    check(6, 2, 3, 1);
    check.debug(0, 5, 2, 3);
    check(1, 9, 1, 1);
    check(34549172, 50, 100, 25);
    check(418930126, 37, 17, 7);
  }
  return 0;
}

Settings;
