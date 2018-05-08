
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

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0020: Valid Parentheses." << endl;

    auto && f = testAnswer<bool, string>;
    f(true, "");
    f(false, "(");
    f(true, "()");
    f(true, "()[]{}");
    f(false, "(]");
    f(false, "([)]");
    f(true, "{[]}");

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.isValid(const_cast<_Types &>(args)...);

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
