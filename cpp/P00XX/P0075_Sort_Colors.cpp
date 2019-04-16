
#include "leetcode.hpp"

class Solution {
public:
  void sortColors(vector<int> & nums) {
    auto _First = nums.begin();
    auto _Last = nums.end();
    for (auto _Ptr = _First; _Ptr != _Last;) {
      if (*_Ptr == 0) {
        *_Ptr = *_First;
        *_First = 0;
        if (_Ptr == _First) ++_Ptr;
        ++_First;
      } else if (*_Ptr == 1) {
        ++_Ptr;
      } else if (*_Ptr == 2) {
        --_Last;
        *_Ptr = *_Last;
        *_Last = 2;
      }
    }
  }
  vector<int> sortColorsCheck(vector<int> & nums) {
    sortColors(nums);
    return move(nums);
  }
};

int main() {
  {
    auto check = solve(&Solution::sortColorsCheck);
    check({ 0, 0, 1, 1, 2, 2 }, { 2, 0, 2, 1, 1, 0 });
    check({}, {});
    check({ 0 }, { 0 });
    check({ 1 }, { 1 });
    check({ 2 }, { 2 });
    check({ 0, 1 }, { 0, 1 });
    check({ 0, 1 }, { 1, 0 });
    check({ 1, 2 }, { 1, 2 });
    check({ 1, 2 }, { 2, 1 });
    check({ 0, 2 }, { 0, 2 });
    check({ 0, 2 }, { 2, 0 });
    check({ 0, 0, 0 }, { 0, 0, 0 });
    check({ 0, 0, 1 }, { 0, 0, 1 });
    check({ 0, 0, 2 }, { 0, 0, 2 });
    check({ 0, 0, 1 }, { 0, 1, 0 });
    check({ 0, 1, 1 }, { 0, 1, 1 });
    check({ 0, 1, 2 }, { 0, 1, 2 });
    check({ 0, 0, 2 }, { 0, 2, 0 });
    check({ 0, 1, 2 }, { 0, 2, 1 });
    check({ 0, 2, 2 }, { 0, 2, 2 });
    check({ 0, 0, 1 }, { 1, 0, 0 });
    check({ 0, 1, 1 }, { 1, 0, 1 });
    check({ 0, 1, 2 }, { 1, 0, 2 });
    check({ 0, 1, 1 }, { 1, 1, 0 });
    check({ 1, 1, 1 }, { 1, 1, 1 });
    check({ 1, 1, 2 }, { 1, 1, 2 });
    check({ 0, 1, 2 }, { 1, 2, 0 });
    check({ 1, 1, 2 }, { 1, 2, 1 });
    check({ 1, 2, 2 }, { 1, 2, 2 });
    check({ 0, 0, 2 }, { 2, 0, 0 });
    check({ 0, 1, 2 }, { 2, 0, 1 });
    check({ 0, 2, 2 }, { 2, 0, 2 });
    check({ 0, 1, 2 }, { 2, 1, 0 });
    check({ 1, 1, 2 }, { 2, 1, 1 });
    check({ 1, 2, 2 }, { 2, 1, 2 });
    check({ 0, 2, 2 }, { 2, 2, 0 });
    check({ 1, 2, 2 }, { 2, 2, 1 });
    check({ 2, 2, 2 }, { 2, 2, 2 });
  }
  return 0;
}

Settings;
