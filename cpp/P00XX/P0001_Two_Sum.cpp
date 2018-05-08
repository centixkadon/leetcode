
#include "leetcode.hpp"

class Solution {
public:
  vector<int> twoSum(vector<int> & nums, int target) {
    map<int, size_t> m;
    for (size_t i = 0; i < nums.size(); ++i) m[nums[i]] = i;
    for (size_t i = 0; i < nums.size(); ++i) {
      auto p = m.find(target - nums[i]);
      if ((p != m.end()) && (i != p->second)) return { static_cast<int>(i), static_cast<int>(p->second) };
    }
    return { 0, 1 };
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0001: Two Sum." << endl;

    auto && f = testAnswer<vector<int>, vector<int>, int>;
    f({ 0, 1 }, { 2, 7, 11, 15 }, 9);
    f({ 1, 3 }, { 2, 7, 11, 15 }, 22);
    f({ 1, 2 }, { 3, 2, 4 }, 6);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.twoSum(const_cast<_Types &>(args)...);

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
