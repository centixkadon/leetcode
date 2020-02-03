
#include "leetcode.hpp"

class Solution {
public:
  void nextPermutation(vector<int> & nums) {
    if (nums.size() < 2) return;
    for (size_t i = nums.size() - 1; i > 0; --i) {
      size_t j = i - 1;
      if (nums[j] < nums[i]) {
        for (size_t k = nums.size() - 1; k >= i; --k) {
          if (nums[k] > nums[j]) {
            auto tmp = nums[j];
            nums[j] = nums[k];
            nums[k] = tmp;
            j = i;
            break;
          }
        }
      }
      if (j == 0 || j == i) {
        for (size_t i = j; i < ((j + nums.size()) >> 1); ++i) {
          auto tmp = nums[i];
          nums[i] = nums[nums.size() - i + j - 1];
          nums[nums.size() - i + j - 1] = tmp;
        }
        break;
      }
    }
  }
  vector<int> nextPermutationCheck(vector<int> & nums) {
    nextPermutation(nums);
    return move(nums);
  }
};

int main() {
  {
    auto check = solve(&Solution::nextPermutationCheck);
    check({ 1, 3, 2 }, { 1, 2, 3 });
    check({ 1, 2, 3 }, { 3, 2, 1 });
    check({ 1, 5, 1 }, { 1, 1, 5 });
  }
  return 0;
}

Settings;
