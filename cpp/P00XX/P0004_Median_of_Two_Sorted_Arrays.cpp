
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

int main() {
  {
    auto check = solve(&Solution::findMedianSortedArrays);
    check(0.0, {}, {});
    check(1.0, { 1 }, {});
    check(1.0, {}, { 1 });
    check(2.5, {}, { 2, 3 });
    check(2.0, { 1, 3 }, { 2 });
    check(2.5, { 1, 2 }, { 3, 4 });
    check(2.5, { 1, 3 }, { 2, 4 });
    check(2.5, { 1, 4 }, { 2, 3 });
    check(2.5, { 2, 3 }, { 1, 4 });
    check(2.5, { 2, 4 }, { 1, 3 });
    check(2.5, { 3, 4 }, { 1, 2 });
  }
  return 0;
}

Settings;
