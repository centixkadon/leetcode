
#include "leetcode.hpp"

class Solution {
public:
  inline bool turn_left(vector<int> const & a, vector<int> const & b, vector<int> const & c) {
    return int64_t(b[1] - a[1]) * int64_t(c[0] - b[0]) + int64_t(a[0] - b[0]) * int64_t(c[1] - b[1]) < int64_t(0);
  }

  bool visitOrderDfs(vector<int> & ans, vector<int> & toVisit, vector<vector<int>> const & points, string const & direction, size_t i = 0) {
    if (i == ans.size()) { return true; }

    for (size_t j = i; j < toVisit.size(); ++j) {
      bool t = (i == 0) || (i == 1);
      if (!t) t = (direction[i - 2] == 'L') == turn_left(points[ans[i - 2]], points[ans[i - 1]], points[toVisit[j]]);
      if (t) {
        ans[i] = toVisit[j];
        swap(toVisit[i], toVisit[j]);
        if (visitOrderDfs(ans, toVisit, points, direction, i + 1)) return true;
        swap(toVisit[i], toVisit[j]);
      }
    }
    return false;
  }

  vector<int> visitOrder(vector<vector<int>> & points, string direction) {
    vector<int> toVisit(points.size());
    for (size_t i = 0; i < points.size(); ++i) toVisit[i] = int(i);

    vector<int> ans(points.size());
    visitOrderDfs(ans, toVisit, points, direction);
    return move(ans);
  }

  bool visitOrderAnswer(vector<int> & ans, vector<vector<int>> & points, string direction) {
    for (size_t i = 0; i < direction.size(); ++i) {
      if ((direction[i] == 'L') != turn_left(points[ans[i]], points[ans[i + 1]], points[ans[i + 2]])) return false;
    }
    return true;
  }

  bool visitOrderTest(vector<vector<int>> & points, string direction) {
    auto ans = visitOrder(points, direction);
    for (size_t i = 0; i < direction.size(); ++i) {
      if ((direction[i] == 'L') != turn_left(points[ans[i]], points[ans[i + 1]], points[ans[i + 2]])) return false;
    }
    return true;
  }
};

int main() {
  {
    auto check = solve(&Solution::turn_left);
    check(true, { 0, -1 }, { 0, 0 }, { -1, -2 });
    check(true, { 0, -1 }, { 0, 0 }, { -1, -1 });
    check(true, { 0, -1 }, { 0, 0 }, { -2, -1 });
    check(true, { 0, -1 }, { 0, 0 }, { -2, 0 });
    check(true, { 0, -1 }, { 0, 0 }, { -2, 1 });
    check(true, { 0, -1 }, { 0, 0 }, { -1, 1 });
    check(true, { 0, -1 }, { 0, 0 }, { -1, 2 });
    check(false, { 0, -1 }, { 0, 0 }, { 1, 2 });
    check(false, { 0, -1 }, { 0, 0 }, { 1, 1 });
    check(false, { 0, -1 }, { 0, 0 }, { 2, 1 });
    check(false, { 0, -1 }, { 0, 0 }, { 2, 0 });
    check(false, { 0, -1 }, { 0, 0 }, { 2, -1 });
    check(false, { 0, -1 }, { 0, 0 }, { 1, -1 });
    check(false, { 0, -1 }, { 0, 0 }, { 1, -2 });

    check(true, { -1, -1 }, { 0, 0 }, { -2, -1 });
    check(true, { -1, -1 }, { 0, 0 }, { -1, 0 });
    check(true, { -1, -1 }, { 0, 0 }, { -1, 1 });
    check(true, { -1, -1 }, { 0, 0 }, { 0, 1 });
    check(true, { -1, -1 }, { 0, 0 }, { 1, 2 });
    check(false, { -1, -1 }, { 0, 0 }, { 2, 1 });
    check(false, { -1, -1 }, { 0, 0 }, { 1, 0 });
    check(false, { -1, -1 }, { 0, 0 }, { 1, -1 });
    check(false, { -1, -1 }, { 0, 0 }, { 0, -1 });
    check(false, { -1, -1 }, { 0, 0 }, { -1, -2 });
  }
  {
    auto check = solve(&Solution::visitOrderAnswer);
    check(true, { 0, 2, 1, 3 }, { { 1, 1 }, { 1, 4 }, { 3, 2 }, { 2, 1 } }, "LL");
    check(true, { 0, 3, 1, 2 }, { { 1, 3 }, { 2, 4 }, { 3, 3 }, { 2, 1 } }, "LR");
  }
  {
    auto check = solve(&Solution::visitOrderTest);
    check(true, { { 1, 1 }, { 1, 4 }, { 3, 2 }, { 2, 1 } }, "LL");
    check(true, { { 1, 3 }, { 2, 4 }, { 3, 3 }, { 2, 1 } }, "LR");
    for (size_t index = 0; index < 1000; ++index) {
      vector<vector<int>> points;
      mt19937_64 rd_e;
      uniform_int_distribution<int> rd_d(1, 10000);
      string direction(998, 'L');
      for (size_t i = 0; i < 1000; ++i) points.push_back({ rd_d(rd_e), rd_d(rd_e) });
      for (auto & c : direction) {
        if (rd_d(rd_e) & 1) c = 'R';
      }
      check(true, points, direction);
    }
  }
  return 0;
}

Settings;
