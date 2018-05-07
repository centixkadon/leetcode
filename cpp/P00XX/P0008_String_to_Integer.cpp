
#include "leetcode.hpp"

class Solution {
public:
  int myAtoi(string str) {
    int const maxi = numeric_limits<int>::max(), mini = numeric_limits<int>::min();

    bool minus = false;
    string numerical = "0123456789";
    size_t i = string::npos, j = str.size();
    for (size_t k = str.find_first_not_of(' '); k < str.size(); ++k) {
      if ((str[k] == '+') || (str[k] == '-')) {
        minus = str[k] == '-';
        ++k;
        if (k == str.size()) break;
      }

      if (numerical.find(str[k]) != string::npos) i = k;
      break;
    }
    if (i == string::npos) return 0;
    for (size_t k = i + 1; k < str.size(); ++k) {
      if (numerical.find(str[k]) == string::npos) {
        j = k;
        break;
      }
    }

    string s = str.substr(i, j - i);
    int ans = 0;
    for (auto c : s) {
      if (ans > maxi / 10) return maxi;
      if (ans < mini / 10) return mini;
      ans *= 10;

      int k = c - '0';
      if (minus) {
        if (ans < mini + k) return mini;
        ans -= k;
      } else {
        if (ans > maxi - k) return maxi;
        ans += k;
      }
    }
    return ans;
  }
} s;

class TestCase {
public:
  TestCase() {
    cout << "P0008: String to Integer (atoi)." << endl;

    auto && f = TestCase::testAnswer<int, string>;
    f(0, "words and 987");
    f(0, "");
    f(0, "-");
    f(0, "-0");
    f(0, "-00");
    f(-1, "-001");
    f(-1, "-001-1111");
    f(-9, "-9");
    f(0, "+-2");
    f(9, "9");
    f(42, "42");
    f(-42, "   -42");
    f(4193, "4193 with words");
    f(-2147483648, "-2147483649");
    f(2147483647, "2147483648");
    f(-2147483648, "-91283472332");
    f(2147483647, "91283472332");

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.myAtoi(const_cast<_Types &>(args)...);

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
