
#include "leetcode.hpp"

class Solution {
public:
  int maximalRectangle(vector<vector<char>> & matrix) {
    if (matrix.empty()) return 0;
    if (matrix.front().empty()) return 0;

    size_t n = matrix.front().size();
    vector<int> heights(n + 1, 0);

    int ans = 0;
    for (auto & v : matrix) {
      for (size_t i = 0; i < n; ++i) {
        if (v[i] == '0') {
          heights[i] = 0;
        } else {
          ++heights[i];
        }
      }

      ans = max(ans, largestRectangleArea(heights));
    }

    return ans;
  }

  int largestRectangleArea(vector<int> & heights) {
    if (heights.empty() || heights.back() != 0) heights.push_back(0);

    int ans = 0;
    stack<size_t> s;
    for (size_t i = 0; i < heights.size(); ++i) {
      while (!s.empty() && heights[s.top()] >= heights[i]) {
        auto height = heights[s.top()];
        s.pop();
        auto j = 0;
        if (!s.empty()) j = s.top() + 1;
        ans = max(ans, static_cast<int>((i - j) * height));
      }

      s.push(i);
    }

    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::maximalRectangle);
    check(0, {});
    check(0, { "" });
    check(6, { "10100", "10111", "11111", "10010" });
    check(2, { "10", "10" });
  }
  return 0;
}

Settings;
