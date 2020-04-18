
#include "leetcode.hpp"

class Solution {
public:
  bool searchMatrix(vector<vector<int>> & matrix, int target) {
    if (matrix.empty()) return false;
    if (matrix.front().empty()) return false;

    size_t m = matrix.size(), i = 0, j = matrix.front().size() - 1;
    while (true) {
      if (matrix[i][j] == target) return true;
      if (matrix[i][j] < target) {
        ++i;
        if (i == m) return false;
      } else {
        if (j == 0) return false;
        --j;
      }
    }
  }
};

int main() {
  {
    auto check = solve(&Solution::searchMatrix);
    check(false, {}, 5);
    check(false, { {} }, 5);
    check(true, { { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 } }, 5);
    check(false, { { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 } }, 20);
  }
  return 0;
}

Settings;
