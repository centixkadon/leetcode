
#include "leetcode.hpp"

class Solution {
public:
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
    cout << "P0012: Integer to Roman." << endl;

    auto && f = testAnswer<string, int>;
    f("III", 3);
    f("IV", 4);
    f("IX", 9);
    f("LVIII", 58);
    f("MCMXCIV", 1994);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.intToRoman(const_cast<_Types &>(args)...);

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
