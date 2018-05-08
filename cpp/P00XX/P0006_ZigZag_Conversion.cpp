
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

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0006: ZigZag Conversion." << endl;

    auto && f = testAnswer<string, string, int>;
    f("ABC", "ABC", 1);
    f("PAHNAPLSIIGYIR", "PAYPALISHIRING", 3);
    f("PINALSIGYAHRPI", "PAYPALISHIRING", 4);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.convert(const_cast<_Types &>(args)...);

    ++Q;
    if (!compareAnswer(ans, _ans)) {
      printParameterPacks(cout << Q << " Q: ", args...) << endl;
      cout << Q << " O: " << ans << endl;
      cout << Q << " X: " << _ans << endl;
      ++X;
    }
  }
};

int main() {
  TestCase();

  return 0;
}
