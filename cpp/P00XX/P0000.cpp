
#include "leetcode.hpp"

class Solution {
public:
  int test(int a) { return a; }
};

class TestCase {
public:
  TestCase() : s(), X(0), Q(0) {
    test(1, 1);
    test(2, 2);
    test(4, 3);
    test(8, 4);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  bool compare(_Ty const & l, _Ty const & r) { return l == r; }

  void test(int ans, int in) {
    auto && _ans = s.test(in);

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
  cout << "P0000: Template." << endl;

  TestCase();

  return 0;
}
