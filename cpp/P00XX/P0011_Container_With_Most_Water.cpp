
#include "leetcode.hpp"

class Solution {
public:
  int maxArea(vector<int> & height) {
    size_t l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
      ans = max(ans, static_cast<int>((r - l) * min(height[l], height[r])));
      if (height[l] <= height[r])
        ++l;
      else
        --r;
    }
    return ans;
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0011: Container With Most Water." << endl;

    auto && f = testAnswer<int, vector<int>>;
    f(1, { 1, 1000 });
    f(10, { 1, 1, 10, 10, 1, 1 });
    f(5, { 1, 1, 2, 2, 1, 1 });

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.maxArea(const_cast<_Types &>(args)...);

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
