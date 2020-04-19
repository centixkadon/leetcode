
#include "leetcode.hpp"

class Solution {
public:
  int numWays(int n, vector<vector<int>> & relation, int k) {
    vector<list<size_t>> v(n);
    for (auto & dir : relation) {
      v[dir[0]].push_back(dir[1]);
    }

    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int kk = 0; kk < k; ++kk) {
      vector<int> next(n, 0);
      for (size_t i = 0; i < dp.size(); ++i) {
        for (auto j : v[i]) {
          next[j] += dp[i];
        }
      }
      dp = move(next);
    }

    return dp[n - 1];
  }
};

int main() {
  {
    auto check = solve(&Solution::numWays);
    check(3, 5, { { 0, 2 }, { 2, 1 }, { 3, 4 }, { 2, 3 }, { 1, 4 }, { 2, 0 }, { 0, 4 } }, 3);
    check(0, 3, { { 0, 2 }, { 2, 1 } }, 2);
  }
  return 0;
}

Settings;
