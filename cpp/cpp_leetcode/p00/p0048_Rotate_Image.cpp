
#include "leetcode.hpp"

class Solution {
public:
  void rotate(vector<vector<int>> & matrix) {
    size_t n = matrix.size();
    for (size_t i = 0; i < (n >> 1); ++i)
      for (size_t j = i; j < n - i - 1; ++j) {
        auto tmp = matrix[i][j];
        matrix[i][j] = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = tmp;
      }
  }
  vector<vector<int>> rotateCheck(vector<vector<int>> & matrix) {
    rotate(matrix);
    return move(matrix);
  }
};

int main() {
  {
    auto check = solve(&Solution::rotateCheck);
    check({ {} }, { {} });
    check({ { 1 } }, { { 1 } });
    check({ { 7, 4, 1 }, { 8, 5, 2 }, { 9, 6, 3 } }, { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
    check({ { 15, 13, 2, 5 }, { 14, 3, 4, 1 }, { 12, 6, 8, 9 }, { 16, 7, 10, 11 } }, { { 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 } });
  }
  return 0;
}

Settings;
