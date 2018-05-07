
#include "leetcode.hpp"

class Solution {
public:
  bool isMatch(string s, string p) {
    return _isMatch(s, p, 0, 0);
  }

private:
  static bool _isMatch(string const & s, string const & p, size_t i, size_t j) {
    if ((i == s.size()) && (j == p.size())) return true;

    if ((j + 1 < p.size()) && (p[j + 1] == '*')) {
      if (_isMatch(s, p, i, j + 2)) return true;
      for (size_t k = i; k < s.size(); ++k) {
        if ((p[j] == '.') || (p[j] == s[k])) {
          if (_isMatch(s, p, k + 1, j + 2)) return true;
        } else
          break;
      }
    } else if ((i < s.size()) && (j < p.size())) {
      if ((p[j] == '.') || (p[j] == s[i])) return _isMatch(s, p, i + 1, j + 1);
    }
    return false;
  }
} s;

class TestCase {
public:
  TestCase() {
    cout << "P0010: Regular Expression Matching." << endl;

    auto && f = TestCase::testAnswer<bool, string, string>;
    f(false, "a", "aa");
    f(false, "aa", "a");
    f(true, "aa", "a*");
    f(true, "ab", ".*");
    f(true, "aab", "c*a*b");
    f(false, "mississippi", "mis*is*p*.");
    f(true, "mississippi", "mis*is*ip*.");
    f(false, "", ".....");

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.isMatch(const_cast<_Types &>(args)...);

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
