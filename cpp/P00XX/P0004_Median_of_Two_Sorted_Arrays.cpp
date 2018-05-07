
#include "leetcode.hpp"

class Solution {
public:
  double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
    int m = nums1.size(), n = nums2.size();
    int half = (m + n) >> 1;
    bool odd = (m + n) & 1;
    int l = max(half - n, 0), r = min(half, m) + 1;

    if ((m == 0) && (n == 0))
      return 0.0;
    else if (m == 0)
      return odd ? nums2[half] : ((nums2[half - 1] + nums2[half]) / 2.0);
    else if (n == 0)
      return odd ? nums1[half] : ((nums1[half - 1] + nums1[half]) / 2.0);

    while (true) {
      int i = (l + r) >> 1;
      int j = half - i;
      int left_max, right_min;
      if (i == 0)
        left_max = nums2[j - 1];
      else if (j == 0)
        left_max = nums1[i - 1];
      else
        left_max = max(nums1[i - 1], nums2[j - 1]);
      if (i == m)
        right_min = nums2[j];
      else if (j == n)
        right_min = nums1[i];
      else
        right_min = min(nums1[i], nums2[j]);

      if (left_max <= right_min) {
        return odd ? right_min : ((left_max + right_min) / 2.0);
      } else {
        if (nums2[j] < nums1[i - 1])
          r = i;
        else
          l = i;
      }
    }
  }
} s;

class TestCase {
public:
  TestCase() {
    cout << "P0004: Median of Two Sorted Arrays." << endl;

    auto && f = testAnswer<double, vector<int>, vector<int>>;
    f(0.0, {}, {});
    f(1.0, { 1 }, {});
    f(1.0, {}, { 1 });
    f(2.5, {}, { 2, 3 });
    f(2.0, { 1, 3 }, { 2 });
    f(2.5, { 1, 2 }, { 3, 4 });
    f(2.5, { 1, 3 }, { 2, 4 });
    f(2.5, { 1, 4 }, { 2, 3 });
    f(2.5, { 2, 3 }, { 1, 4 });
    f(2.5, { 2, 4 }, { 1, 3 });
    f(2.5, { 3, 4 }, { 1, 2 });

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.findMedianSortedArrays(const_cast<_Types &>(args)...);

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
