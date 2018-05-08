
#include "leetcode.hpp"

class Solution {
public:
  string longestPalindrome(string s) {
    string ans = "";
    size_t n = s.size();
    for (size_t k = 0; k <= n; ++k) {
      {
        size_t i = k, j = k;
        while ((0 < i) && (j < n) && (s[i - 1] == s[j])) --i, ++j;
        if (j - i > ans.size()) ans = s.substr(i, j - i);
      }
      {
        size_t i = k, j = k + 1;
        while ((0 < i) && (j < n) && (s[i - 1] == s[j])) --i, ++j;
        if ((j <= n) && (j - i > ans.size())) ans = s.substr(i, j - i);
      }
    }
    return ans;
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0005: Longest Palindromic Substring." << endl;

    auto && f = testAnswer<string, string>;
    f("", "");
    f("a", "a");
    f("a", "abcd");
    f("bab", "babad");
    f("bb", "cbbd");

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.longestPalindrome(const_cast<_Types &>(args)...);

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
