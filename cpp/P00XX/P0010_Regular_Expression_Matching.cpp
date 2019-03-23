
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
};

int main() {
  {
    auto check = solve(&Solution::isMatch);
    check(false, "a", "aa");
    check(false, "aa", "a");
    check(true, "aa", "a*");
    check(true, "ab", ".*");
    check(true, "aab", "c*a*b");
    check(false, "mississippi", "mis*is*p*.");
    check(true, "mississippi", "mis*is*ip*.");
    check(false, "", ".....");
  }
  return 0;
}

Settings;
