
#include "leetcode.hpp"

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> & board) {
    vector<bitset<n>> row(n), col(n), block(n);
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j) {
        auto c = board[i][j];
        if (c != '.') {
          size_t pos = c - '1';
          if (row[i].test(pos)) return false;
          row[i].set(pos);
          if (col[j].test(pos)) return false;
          col[j].set(pos);
          if (block[i / 3 * 3 + j / 3].test(pos)) return false;
          block[i / 3 * 3 + j / 3].set(pos);
        }
      }
    return true;
  }

private:
  static size_t const n = 9;
};

int main() {
  {
    auto check = solve(&Solution::isValidSudoku);
    check(true, { "53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79" });
    check(false, { "83..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79" });
  }
  return 0;
}

Settings;
