
#include "leetcode.hpp"

class Solution {
  static size_t const m = 3;
  static size_t const n = m * m;

public:
  inline void setx(vector<bitset<n>> & row, vector<bitset<n>> & col, vector<bitset<n>> & block, vector<vector<size_t>> & b, size_t i, size_t j, size_t k, size_t x) {
    b[i][j] = one << x;
    row[i].set(x);
    col[j].set(x);
    block[k].set(x);
  }
  inline void resetx(vector<bitset<n>> & row, vector<bitset<n>> & col, vector<bitset<n>> & block, vector<vector<size_t>> & b, size_t i, size_t j, size_t k, size_t x) {
    b[i][j] = 0;
    row[i].reset(x);
    col[j].reset(x);
    block[k].reset(x);
  }

  bool solveSudoku(size_t cnt, vector<bitset<n>> row, vector<bitset<n>> col, vector<bitset<n>> block, vector<vector<size_t>> & b) {
    auto tmp = b;

    while (true) {
      bool t = true;
      for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j) {
          if (b[i][j] == 0) {
            size_t k = i / m * m + j / m;
            auto left = ~(row[i] | col[j] | block[k]);
            size_t xc = left.count();
            if (xc == 0) {
              b = tmp;
              return false;
            }
            if (xc == 1) {
              b[i][j] = left.to_ullong();
              --cnt;
              row[i] |= left;
              col[j] |= left;
              block[k] |= left;
              t = false;
            } else {
              for (size_t x = 0; x < n; ++x) {
                if (left.test(x)) {
                  size_t xc = 0;
                  for (size_t p = 0; p < m; ++p)
                    for (size_t q = 0; q < m; ++q) {
                      size_t ii = i / m * m + p, jj = j / m * m + q;
                      if (ii == i && jj == j) continue;
                      if (b[ii][jj] != 0 || row[ii].test(x) || col[jj].test(x)) ++xc;
                    }
                  if (xc + 1 == n) {
                    setx(row, col, block, b, i, j, k, x);
                    --cnt;
                    t = false;
                    break;
                  }

                  xc = 0;
                  for (size_t q = 0; q < n; ++q) {
                    if (q == j) continue;
                    size_t kk = i / m * m + q / m;
                    if (b[i][q] != 0 || col[q].test(x) || block[kk].test(x)) ++xc;
                  }
                  if (xc + 1 == n) {
                    setx(row, col, block, b, i, j, k, x);
                    --cnt;
                    t = false;
                    break;
                  }

                  xc = 0;
                  for (size_t p = 0; p < n; ++p) {
                    if (p == i) continue;
                    size_t kk = p / m * m + j / m;
                    if (b[p][j] != 0 || row[p].test(x) || block[kk].test(x)) ++xc;
                  }
                  if (xc + 1 == n) {
                    setx(row, col, block, b, i, j, k, x);
                    --cnt;
                    t = false;
                    break;
                  }
                }
              }
            }
          }
        }
      if (t) break;
    }

    printBoard(cnt, b);
    if (cnt == 0) return true;

    set<vector<size_t>> counts;
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j) {
        if (b[i][j] == 0) {
          size_t k = i / 3 * 3 + j / 3;
          auto left = ~(row[i] | col[j] | block[k]);
          counts.insert({ left.count(), i, j });
        }
      }

    for (auto const & count : counts) {
      size_t i = count[1];
      size_t j = count[2];
      size_t k = i / 3 * 3 + j / 3;
      auto left = ~(row[i] | col[j] | block[k]);
      for (size_t x = 0; x < n; ++x) {
        if (left.test(x)) {
          setx(row, col, block, b, i, j, k, x);
          if (solveSudoku(cnt - 1, row, col, block, b)) return true;
          resetx(row, col, block, b, i, j, k, x);
          printBoard(cnt, b);
        }
      }
    }

    b = tmp;
    return false;
  }
  void solveSudoku(vector<vector<char>> & board) {
    size_t cnt = n * n;
    vector<bitset<n>> row(n), col(n), block(n);
    vector<vector<size_t>> b(n, vector<size_t>(n, 0));
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j) {
        auto c = board[i][j];
        size_t k = i / 3 * 3 + j / 3;
        if (c != '.') {
          size_t x = c - '1';
          b[i][j] = one << x;
          --cnt;
          row[i].set(x);
          col[j].set(x);
          block[k].set(x);
        }
      }

    printBoard(cnt, b);
    solveSudoku(cnt, row, col, block, b);

    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j)
        for (size_t x = 0; x < n; ++x)
          if (b[i][j] & (one << x)) {
            board[i][j] = '1' + x;
            break;
          }
  }
  vector<vector<char>> solveSudokuCheck(vector<vector<char>> & board) {
    solveSudoku(board);
    return move(board);
  }

private:
  static size_t const one = 1;

  void printBoard(size_t cnt, vector<vector<size_t>> const & b) {
    return;
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        vector<char> xs;
        for (size_t x = 0; x < n; ++x)
          if (b[i][j] & (one << x)) {
            xs.push_back('1' + x);
          }
        if (xs.empty()) cout << ".";
        if (xs.size() == 1) cout << xs[0];
        if (xs.size() > 1) cout << " ";
      }
      cout << endl;
    }
    cout << "count: " << cnt << endl;
    string s;
    getline(cin, s);
  }
};

int main() {
  {
    auto check = solve(&Solution::solveSudokuCheck);
    check({ "534678912", "672195348", "198342567", "859761423", "426853791", "713924856", "961537284", "287419635", "345286179" }, { "53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79" });
    check({ "123456789", "456789123", "789123456", "231674895", "875912364", "694538217", "317265948", "542897631", "968341572" }, { ".........", ".........", ".........", ".........", ".........", ".........", ".........", ".........", "........." });
    check({ "634.78912", ".72195348", "198342567", "859761423", "426853791", "713924856", "961537284", "287419635", "345286179" }, { "634.78912", ".72195348", "198342567", "859761423", "426853791", "713924856", "961537284", "287419635", "345286179" });
    check({ "519748632", "783652419", "426139875", "357986241", "264317598", "198524367", "975863124", "832491756", "641275983" }, { "..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.." });
  }
  return 0;
}

Settings;
