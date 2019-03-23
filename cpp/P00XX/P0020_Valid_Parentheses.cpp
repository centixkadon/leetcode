
#include "leetcode.hpp"

class Solution {
public:
  bool isValid(string s) {
    vector<char> stack;
    for (auto c : s) {
      int i = 1;
      switch (c) {
      case '(':
      case '[':
      case '{':
        stack.push_back(c);
        break;
      case ']':
      case '}':
        ++i;
      case ')':
        if (stack.empty()) return false;
        if (c - stack.back() == i)
          stack.pop_back();
        else {
          return false;
        }
        break;
      }
    }
    return stack.empty();
  }
};

int main() {
  {
    auto check = solve(&Solution::isValid);
    check(true, "");
    check(false, "(");
    check(true, "()");
    check(true, "()[]{}");
    check(false, "(]");
    check(false, "([)]");
    check(true, "{[]}");
  }
  return 0;
}

Settings;
