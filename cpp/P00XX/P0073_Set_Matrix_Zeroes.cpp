
#include "leetcode.hpp"

class Solution {
public:
  void setZeroes(vector<vector<int>> & matrix) {
    if (matrix.empty()) return;
    if (matrix[0].empty()) return;
    bool t = false;
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == 0) {
          if (i == 0)
            t = true;
          else
            matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    for (size_t i = 1; i < matrix.size(); ++i) {
      if (matrix[i][0] == 0) matrix[i].assign(matrix[i].size(), 0);
    }
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      if (matrix[0][j] == 0) {
        for (size_t i = 0; i < matrix.size(); ++i) matrix[i][j] = 0;
      }
    }
    if (t) matrix[0].assign(matrix[0].size(), 0);
  }
  vector<vector<int>> setZeroesCheck(vector<vector<int>> & matrix) {
    setZeroes(matrix);
    return move(matrix);
  }
};

int main() {
  {
    auto check = solve(&Solution::setZeroesCheck);
    check({ { 1, 0, 1 }, { 0, 0, 0 }, { 1, 0, 1 } }, { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } });
    check({ { 0, 0, 0, 0 }, { 0, 4, 5, 0 }, { 0, 3, 1, 0 } }, { { 0, 1, 2, 0 }, { 3, 4, 5, 2 }, { 1, 3, 1, 5 } });
    check({}, {});
    check({ {} }, { {} });
    check({ { 1 } }, { { 1 } });
    check({ { 0 } }, { { 0 } });
    check({ { 0, 0, 0 }, { 1, 0, 1 }, { 1, 0, 1 } }, { { 1, 0, 1 }, { 1, 1, 1 }, { 1, 1, 1 } });
    check({ { 0, 1, 1 }, { 0, 0, 0 }, { 0, 1, 1 } }, { { 1, 1, 1 }, { 0, 1, 1 }, { 1, 1, 1 } });
  }
  return 0;
}

Settings;
