
#include "leetcode.hpp"

class Solution {
public:
  vector<int> twoSum(vector<int> & nums, int target) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) m[nums[i]] = i;
    for (int i = 0; i < nums.size(); ++i) {
      auto p = m.find(target - nums[i]);
      if ((p != m.end()) && (i != p->second)) return { i, p->second };
    }
    return { 0, 1 };
  }
};

class TestCase {
public:
  TestCase() : s(), X(0), Q(0) {
    test({ 0, 1 }, { 2, 7, 11, 15 }, 9);
    test({ 1, 3 }, { 2, 7, 11, 15 }, 22);
    test({ 1, 2 }, { 3, 2, 4 }, 6);

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  template <typename _Ty>
  bool compare(_Ty const & l, _Ty const & r) { return l == r; }

  void test(vector<int> const & ans, vector<int> const & nums, int target) {
    auto && _ans = s.twoSum(const_cast<vector<int> &>(nums), target);

    if (!compare(ans, _ans)) {
      cout << "Q: " << nums << ", " << target << endl;
      cout << "O: " << ans << endl;
      cout << "X: " << _ans << endl;
      ++X;
    }
    ++Q;
  }

  Solution s;
  size_t X, Q;
};

int main() {
  cout << "P0001: Two Sum." << endl;

  TestCase();

  return 0;
}
