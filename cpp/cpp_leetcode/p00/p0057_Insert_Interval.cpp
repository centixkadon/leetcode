
#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> & intervals, vector<int> & newInterval) {
    if (intervals.empty()) return { newInterval };

    size_t l = 0, r = intervals.size();
    while (l < r) {
      size_t m = (l + r) >> 1;
      if (intervals[m][1] < newInterval[0]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    if (l == intervals.size() || newInterval[1] < intervals[l][0]) {
      intervals.insert(intervals.begin() + l, newInterval);
    } else {
      size_t s = l, r = intervals.size();
      while (l < r) {
        size_t m = (l + r) >> 1;
        if (intervals[m][0] <= newInterval[1]) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      intervals[s][0] = min(intervals[s][0], newInterval[0]);
      intervals[s][1] = max(intervals[l - 1][1], newInterval[1]);
      if (s + 1 != l) {
        for (size_t i = l; i < intervals.size(); ++i) {
          ++s;
          intervals[s] = intervals[i];
        }
        intervals.resize(s + 1);
      }
    }
    return move(intervals);
  }
};

int main() {
  {
    auto check = solve(&Solution::insert);
    check({ { 2, 5 } }, {}, { 2, 5 });
    check({ { 1, 5 }, { 6, 9 } }, { { 1, 3 }, { 6, 9 } }, { 2, 5 });
    check({ { 1, 2 }, { 3, 10 }, { 12, 16 } }, { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } }, { 4, 8 });
    check({ { 1, 2 }, { 3, 5 } }, { { 1, 2 } }, { 3, 5 });
    check({ { 2, 5 } }, { { 2, 3 } }, { 3, 5 });
    check({ { 2, 5 } }, { { 2, 4 } }, { 3, 5 });
    check({ { 2, 5 } }, { { 2, 5 } }, { 3, 5 });
    check({ { 2, 6 } }, { { 2, 6 } }, { 3, 5 });
    check({ { 3, 6 } }, { { 3, 6 } }, { 3, 5 });
    check({ { 3, 6 } }, { { 4, 6 } }, { 3, 5 });
    check({ { 3, 6 } }, { { 5, 6 } }, { 3, 5 });
    check({ { 3, 5 }, { 6, 7 } }, { { 6, 7 } }, { 3, 5 });
    check({ { 1, 1 }, { 2, 4 } }, { { 1, 1 } }, { 2, 4 });
    check({ { 2, 4 } }, { { 2, 2 } }, { 2, 4 });
    check({ { 2, 4 } }, { { 3, 3 } }, { 2, 4 });
    check({ { 2, 4 } }, { { 4, 4 } }, { 2, 4 });
    check({ { 2, 4 }, { 5, 5 } }, { { 5, 5 } }, { 2, 4 });
  }
  return 0;
}

Settings;
