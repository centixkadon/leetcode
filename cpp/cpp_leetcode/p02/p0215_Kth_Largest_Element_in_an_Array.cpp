
#include "leetcode.hpp"

class Solution {
public:
  int findKthLargest(vector<int> & nums, int k) {
    return findKthLargestPartition(nums, 0, nums.size() - 1, nums.size() - k);
  }

  int findKthLargestPartition(vector<int> & v, size_t l, size_t r, size_t k) {
    auto & x = v[r];
    auto & y = v[(l + r) >> 1];
    tie(x, y) = make_tuple(y, x);
    auto i = l;
    for (auto j = l; j < r; ++j) {
      if (v[j] <= x) {
        tie(v[i], v[j]) = make_tuple(v[j], v[i]);
        ++i;
      }
    }
    tie(v[i], x) = make_tuple(x, v[i]);
    if (k < i) return findKthLargestPartition(v, l, i - 1, k);
    if (i < k) return findKthLargestPartition(v, i + 1, r, k);
    return v[k];
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::findKthLargest);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check(6, { 3, 2, 1, 5, 6, 4 }, 1);
    check(5, { 3, 2, 1, 5, 6, 4 }, 2);
    check(4, { 3, 2, 1, 5, 6, 4 }, 3);
    check(3, { 3, 2, 1, 5, 6, 4 }, 4);
    check(2, { 3, 2, 1, 5, 6, 4 }, 5);
    check(1, { 3, 2, 1, 5, 6, 4 }, 6);
    check(4, { 3, 2, 3, 1, 2, 4, 5, 5, 6 }, 4);
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
