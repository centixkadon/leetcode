
#include "leetcode.hpp"

class Solution {
public:
  int longestValidParentheses(string s) {
    if (s.size() < 2) return 0;
    vector<size_t> v(s.size());
    v[0] = (s[0] == '(') ? 0 : npos;

    size_t ans = 0;
    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i] == '(') {
        if (s[i - 1] == '(') {
          v[i] = i;
        } else {
          if (v[i - 1] == npos) {
            v[i] = i;
          } else {
            v[i] = v[i - 1];
          }
        }
      } else {
        if (s[i - 1] == '(') {
          v[i] = v[i - 1];
        } else {
          v[i] = v[i - 1];
          if (v[i] != npos) {
            if (v[i] == 0) {
              v[i] = npos;
            } else {
              v[i] = v[v[i] - 1];
            }
          }
        }
        if (v[i] != npos) {
          ans = max(ans, i + 1 - v[i]);
        }
      }
    }
    return ans;
  }
  static size_t const npos = numeric_limits<size_t>::max();
};

int main() {
  {
    auto check = solve(&Solution::longestValidParentheses);
    check(2, "(()");
    check(4, ")()())");
    check(0, "");
    check(0, "(");
    check(0, ")");
    check(14, "())(()))((((()())(()()))");
  }
  return 0;
}

Settings;
