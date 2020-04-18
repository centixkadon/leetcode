
#include "leetcode.hpp"

class Solution {
public:
  int longestConsecutive(vector<int> & nums) {
    unordered_set<int> xs(nums.begin(), nums.end());

    int ans = 0;
    for (auto x : xs) {
      if (xs.find(x - 1) == xs.end()) {
        int sum = 1;
        for (auto i = x + 1;; ++i) {
          if (xs.find(i) == xs.end()) break;
          ++sum;
        }
        ans = max(ans, sum);
      }
    }

    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::longestConsecutive);
    check(4, { 100, 4, 200, 1, 3, 2 });
  }
  return 0;
}

Settings;
