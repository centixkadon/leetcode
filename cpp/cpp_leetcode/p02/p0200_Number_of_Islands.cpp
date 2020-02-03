
#include "leetcode.hpp"

class Solution {
public:
  int numIslands(vector<vector<char>> & grid) {
    if (grid.empty()) return 0;
    if (grid.front().empty()) return 0;

    m = grid.size();
    n = grid.front().size();
    vector<size_t> v(m * n);
    for (size_t i = 0; i < m * n; ++i) v[i] = i;

    int ans = 0;
    for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j) {
        if (grid[i][j] == '0') {
          --ans;
          continue;
        }
        if (!i && !j) continue;
        if (i && grid[i - 1][j] == '1') v[father(v, hash(i, j))] = father(v, hash(i - 1, j));
        if (j && grid[i][j - 1] == '1') v[father(v, hash(i, j))] = father(v, hash(i, j - 1));
      }

    for (size_t i = 0; i < m * n; ++i) ans += v[i] == i;
    return ans;
  }

  size_t father(vector<size_t> & v, size_t i) {
    if (v[i] == i) return i;
    return v[i] = father(v, v[i]);
  }

  size_t hash(size_t i, size_t j) {
    return i * n + j;
  }

private:
  size_t m, n;
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::numIslands);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check(1, { "11110", "11010", "11000", "00000" });
    check(3, { "11000", "11000", "00100", "00011" });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
