
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
};

class TestCase {
public:
  TestCase() : s(), X(0), Q(0) {
    test(0.0, {}, {});
    test(1.0, { 1 }, {});
    test(1.0, {}, { 1 });
    test(2.5, {}, { 2, 3 });
    test(2.0, { 1, 3 }, { 2 });
    test(2.5, { 1, 2 }, { 3, 4 });
    test(2.5, { 1, 3 }, { 2, 4 });
    test(2.5, { 1, 4 }, { 2, 3 });
    test(2.5, { 2, 3 }, { 1, 4 });
    test(2.5, { 2, 4 }, { 1, 3 });
    test(2.5, { 3, 4 }, { 1, 2 });

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  bool compare(_Ty const & l, _Ty const & r) { return l == r; }

  // double const _e = 0.001;
  // template <>
  // bool compare(double const & l, double const & r) { return (r - _e < l) && (l < r + _e); }

  void test(double ans, vector<int> const & nums1, vector<int> const & nums2) {
    auto && _ans = s.findMedianSortedArrays(const_cast<vector<int> &>(nums1), const_cast<vector<int> &>(nums2));

    ++Q;
    if (!compare(ans, _ans)) {
      cout << Q << " Q: " << nums1 << ", " << nums2 << endl;
      cout << Q << " O: " << ans << endl;
      cout << Q << " X: " << _ans << endl;
      ++X;
    }
  }

  Solution s;
  size_t X, Q;
};

int main() {
  cout << "P0004: Median of Two Sorted Arrays." << endl;

  TestCase();

  return 0;
}
