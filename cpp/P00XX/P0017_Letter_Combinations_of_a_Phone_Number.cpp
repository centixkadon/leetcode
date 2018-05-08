
#include "leetcode.hpp"

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> map = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> ans = { "" };
    for (size_t i = 0; i < digits.size(); ++i) {
      vector<string> tmp;
      string & selects = map[digits[i] - '2'];
      for (auto & s : ans) {
        for (auto c : selects) {
          tmp.push_back(s + c);
        }
      }
      ans = move(tmp);
    }

    return move(ans);
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0017: Letter Combinations of a Phone Number." << endl;

    auto && f = testAnswer<vector<string>, string>;
    f({}, "");
    f({ "a", "b", "c" }, "2");
    f({ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }, "23");

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.letterCombinations(const_cast<_Types &>(args)...);

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
