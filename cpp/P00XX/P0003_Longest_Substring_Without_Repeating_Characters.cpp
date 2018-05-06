
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
};

class TestCase {
public:
  TestCase() : s(), X(0), Q(0) {
    test(3, "abcabcbb");
    test(1, "bbbbb");
    test(3, "pwwkew");
    test(1, "a");
    test(0, "");

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  bool compare(_Ty const & l, _Ty const & r) { return l == r; }

  void test(int ans, string const & in) {
    auto && _ans = s.lengthOfLongestSubstring(in);

    ++Q;
    if (!compare(ans, _ans)) {
      cout << Q << " Q: " << in << endl;
      cout << Q << " O: " << ans << endl;
      cout << Q << " X: " << _ans << endl;
      ++X;
    }
  }

  Solution s;
  size_t X, Q;
};

int main() {
  cout << "P0003: Longest Substring Without Repeating Characters." << endl;

  TestCase();

  return 0;
}
