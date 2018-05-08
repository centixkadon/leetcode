
#include "leetcode.hpp"

class Solution {
public:
  int threeSumClosest(vector<int> & nums, int target) {
    int ans = 0;
    sort(nums.begin(), nums.end());

    int diff = numeric_limits<int>::max();
    for (size_t i = 0; i < nums.size() - 2; ++i) {
      size_t l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum < target)
          ++l;
        else if (sum > target)
          --r;
        else
          return target;

        int k = abs(sum - target);
        if (k < diff) {
          diff = k;
          ans = sum;
        }
      }
    }
    return ans;
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0016: 3Sum Closest." << endl;

    auto && f = testAnswer<int, vector<int>, int>;
    f(2, { -1, 2, 1, -4 }, 1);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.threeSumClosest(const_cast<_Types &>(args)...);

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
