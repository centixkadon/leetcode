
#include "leetcode.hpp"

class Solution {
public:
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
  streambuf * cerr_buffer = cerr.rdbuf();
  // streambuf * cerr_buffer = nullptr;
  cerr_buffer = cerr.rdbuf(cerr_buffer);
  {
    auto check = solve(&Solution::largestRectangleArea);
    check(10, { 2, 1, 5, 6, 2, 3 });
    check(0, {});
    check(1, { 1 });
    check(2, { 1, 1 });
    check(3, { 2, 1, 2 });
    check(8, { 5, 4, 1, 2 });
    check(15, { 2, 2, 3, 4, 5, 3, 4 });
    check(14, { 6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3 });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
