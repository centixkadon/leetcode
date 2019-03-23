
#include "leetcode.hpp"

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<vector<char>> v(numRows);
    for (auto & str : v) str.reserve(s.size());

    size_t j = 0;
    bool t = true;
    for (auto c : s) {
      v[j].push_back(c);
      j = t ? (j + 1) : j - 1;
      if ((j == 0) || (j == v.size() - 1)) t = !t;
    }

    vector<char> ans;
    ans.reserve(s.size());
    for (auto & s : v)
      for (auto c : s) ans.push_back(c);
    return string(ans.begin(), ans.end());
  }
};

int main() {
  {
    auto check = solve(&Solution::convert);
    check("ABC", "ABC", 1);
    check("PAHNAPLSIIGYIR", "PAYPALISHIRING", 3);
    check("PINALSIGYAHRPI", "PAYPALISHIRING", 4);
  }
  return 0;
}

Settings;
