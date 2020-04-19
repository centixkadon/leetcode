
#include "leetcode.hpp"

class Solution {
public:
  int minCount(vector<int> & coins) {
    int ans = 0;
    for (auto coin : coins) {
      ans += (coin - 1) / 2 + 1;
    }
    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::minCount);
    check(4, { 4, 2, 1 });
    check(8, { 2, 3, 10 });
  }
  return 0;
}

Settings;
