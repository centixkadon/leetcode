
#include "leetcode.hpp"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    bool m[256];
    for (int c = 0; c < 256; ++c) m[c] = true;

    int ans = 0;
    size_t j = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (m[c]) {
        m[c] = false;
      } else {
        while (s[j] != c) {
          m[s[j]] = true;
          ++j;
        }
        ++j;
      }
      if (i - j + 1 > ans) ans = i - j + 1;
    }
    return ans;
  }
} s;

class TestCase {
public:
  TestCase() {
    cout << "P0003: Longest Substring Without Repeating Characters." << endl;

    auto && f = testAnswer<int, string>;
    f(3, "abcabcbb");
    f(1, "bbbbb");
    f(3, "pwwkew");
    f(1, "a");
    f(0, "");

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.lengthOfLongestSubstring(const_cast<_Types &>(args)...);

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
