
#include "leetcode.hpp"

class Solution {
public:
  int romanToInt(string s) {
    map<char, int> m = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
    int ans = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if ((i + 1 < s.size()) && (m[s[i]] < m[s[i + 1]]))
        ans -= m[s[i]];
      else
        ans += m[s[i]];
    }
    return ans;
  }

  string intToRoman(int num) {
    string r = "IVXLCDM";
    string ans = "";
    for (size_t i = 0; num != 0; ++i) {
      int k = num % 10;
      int p = (k + 1) / 5;
      int j = k - p * 5;
      string mid = "";
      if (p != 0) mid = r[i * 2 + p];
      ans = string(max(-j, 0), r[i * 2]) + mid + string(max(j, 0), r[i * 2]) + ans;

      num /= 10;
    }
    return ans;
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0013: Roman to Integer." << endl;

    auto && f = testAnswer<int, string>;
    for (int i = 0; i < 4000; ++i) f(static_cast<int const>(i), s.intToRoman(i));

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.romanToInt(const_cast<_Types &>(args)...);

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
