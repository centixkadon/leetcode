
#include "leetcode.hpp"

class Solution {
public:
  int trap(vector<int> & height) {
    if (height.size() <= 2) return 0;

    vector<size_t> p(height.size());
    p[0] = npos;

    size_t ans = 0;
    for (size_t i = 1; i < height.size(); ++i) {
      size_t j = i - 1;
      if (height[j] < height[i]) {
        size_t k = p[j];
        while (k != npos) {
          if (height[k] <= height[i]) {
            ans += (height[k] - height[j]) * (i - k - 1);
          } else {
            ans += (height[i] - height[j]) * (i - k - 1);
            break;
          }
          j = k;
          k = p[j];
        }
        p[i] = k;
      } else if (height[j] == height[i]) {
        p[i] = p[j];
      } else {
        p[i] = j;
      }
    }

    return ans;
  }

private:
  static size_t const npos = numeric_limits<size_t>::max();
};

int main() {
  {
    auto check = solve(&Solution::trap);
    check(6, { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 });
    check(3, { 2, 1, 0, 2 });
    check(0, {});
    check(0, { 1 });
    check(0, { 1, 2 });
  }
  return 0;
}

Settings;
