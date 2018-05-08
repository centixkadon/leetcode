
#include "leetcode.hpp"

class Solution {
public:
  string longestCommonPrefix(vector<string> & strs) {
    if (strs.empty()) return "";

    size_t ans = 0;
    for (size_t i = 0; i != (size_t)-1; ++i) {
      char c = ' ';
      bool t = false;
      for (size_t j = 0; j < strs.size(); ++j) {
        if (i == strs[j].size()) {
          t = true;
          break;
        } else {
          if (c == ' ')
            c = strs[j][i];
          else if (c != strs[j][i]) {
            t = true;
            break;
          }
        }
      }
      if (t) {
        ans = i;
        break;
      }
    }

    return strs[0].substr(0, ans);
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0014: Longest Common Prefix." << endl;

    auto && f = testAnswer<string, vector<string>>;
    f("", {});
    f("", { "", "" });
    f("a", { "a" });
    f("fl", { "flower", "flow", "flight" });
    f("", { "dog", "racecar", "car" });

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.longestCommonPrefix(const_cast<_Types &>(args)...);

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
