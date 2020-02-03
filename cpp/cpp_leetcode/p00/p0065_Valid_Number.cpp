
#include "leetcode.hpp"

class Solution {
public:
  bool isNumber(string s) {
    {
      size_t p = s.find_last_not_of(' ');
      if (p == string::npos) return false;
      s.erase(p + 1);
    }
    {
      size_t p = s.find_first_not_of(' ');
      if (p == string::npos) return false;
      s = s.substr(p);
    }

    size_t e = 0;
    for (auto c : s) {
      if (c == 'e') {
        ++e;
        continue;
      }
      if ('0' <= c && c <= '9') continue;
      if (c == '+') continue;
      if (c == '-') continue;
      if (c == '.') continue;
      return false;
    }
    if (e > 1) return false;

    size_t p = s.size();
    if (e == 1) p = s.find_first_of('e');

    size_t q = 0;
    if (q < p && (s[q] == '+' || s[q] == '-')) ++q;
    if (q == p) return false;
    size_t cnt = 0;
    for (size_t i = q; i < p; ++i) {
      if (s[i] == '+') return false;
      if (s[i] == '-') return false;
      if (s[i] == '.') ++cnt;
    }
    if (cnt > 1) return false;
    if (cnt == 1 && p - q == 1) return false;

    if (e == 1) {
      if (p + 1 < s.size() && (s[p + 1] == '+' || s[p + 1] == '-')) ++p;
      if (p + 1 == s.size()) return false;
      for (size_t i = p + 1; i < s.size(); ++i) {
        if (s[i] == '+') return false;
        if (s[i] == '-') return false;
        if (s[i] == '.') return false;
      }
    }

    return true;
  }
};

int main() {
  {
    auto check = solve(&Solution::isNumber);
    check(true, "0");
    check(true, " 0.1 ");
    check(false, "abc");
    check(false, "1 a");
    check(true, "2e10");
    check(true, " -90e3   ");
    check(false, " 1e");
    check(false, "e3");
    check(true, " 6e-1");
    check(false, " 99e2.5 ");
    check(true, "53.5e93");
    check(false, " --6 ");
    check(false, "-+3");
    check(false, "95a54e53");
    check(false, "");
    check(true, "0");
    check(true, "00");
    check(true, "00.0");
    check(true, "+00.0e+0");
    check(true, "-00.0e-0");
    check(false, ".");
    check(true, "0.");
    check(true, ".0");
    check(false, "+.");
    check(true, "+0.");
    check(true, "+.0");
    check(false, "0e+");
    check(true, "0e+1");
  }
  return 0;
}

Settings;
