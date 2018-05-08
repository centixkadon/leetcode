
#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> & nums, int target) {
    if (nums.size() < 4) return {};

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 3; ++i) {
      for (size_t j = i + 1; j < nums.size() - 2; ++j) {
        size_t l = j + 1, r = nums.size() - 1;
        int sum_target = target - nums[i] - nums[j];
        while (l < r) {
          int sum = nums[l] + nums[r];
          if (sum < sum_target)
            ++l;
          else if (sum > sum_target)
            --r;
          else {
            ans.push_back({ nums[i], nums[j], nums[l], nums[r] });
            while ((l < r) && (nums[l] == nums[l + 1])) ++l;
            while ((l < r) && (nums[r] == nums[r - 1])) --r;
            ++l;
            --r;
          }
          while ((j < nums.size() - 3) && (nums[j] == nums[j + 1])) ++j;
        }
        while ((i < nums.size() - 4) && (nums[i] == nums[i + 1])) ++i;
      }
    }

    return move(ans);
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0018: 4Sum." << endl;

    auto && f = testAnswer<vector<vector<int>>, vector<int>, int>;
    // f({}, {}, 0);
    // f({}, { 0, 0, 0 }, 0);
    // f({ { 0, 0, 0, 0 } }, { 0, 0, 0, 0 }, 0);
    // f({ { -1, -1, 1, 1 } }, { -1, 1, -1, 1 }, 0);
    f({ { -1, -1, -1, 3 } }, { -1, -1, -1, -1, -1, -1, -1, 3 }, 0);
    // f({ { -1, 0, 0, 1 }, { -2, -1, 1, 2 }, { -2, 0, 0, 2 } }, { 1, 0, -1, 0, -2, 2 }, 0);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  static bool compareAnswer(vector<vector<int>> & l, vector<vector<int>> & r) {
    for (auto & elem : l) sort(elem.begin(), elem.end());
    for (auto & elem : r) sort(elem.begin(), elem.end());
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    return l == r;
  }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.fourSum(const_cast<_Types &>(args)...);

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
