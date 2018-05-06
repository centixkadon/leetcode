
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

class TestCase {
public:
  TestCase() : s(), X(0), Q(0) {
    test("", "");
    test("a", "a");
    test("a", "abcd");
    test("bab", "babad");
    test("bb", "cbbd");

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  bool compare(_Ty const & l, _Ty const & r) { return l == r; }

  void test(string const & ans, string const & str) {
    auto && _ans = s.longestPalindrome(str);

    ++Q;
    if (!compare(ans, _ans)) {
      cout << Q << " Q: " << str << endl;
      cout << Q << " O: " << ans << endl;
      cout << Q << " X: " << _ans << endl;
      ++X;
    }
  }

  Solution s;
  size_t X, Q;
};

int main() {
  cout << "P0005: Longest Palindromic Substring." << endl;

  TestCase();

  return 0;
}
