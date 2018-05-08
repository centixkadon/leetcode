
#include "leetcode.hpp"

class Solution {
public:
  int test(int a) { return a; }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0000: Template." << endl;

    auto && f = testAnswer<int, int>;
    f(1, 1);
    f(2, 2);
    f(4, 3);
    f(8, 4);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.test(const_cast<_Types &>(args)...);

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
