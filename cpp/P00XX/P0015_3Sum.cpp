
#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> & nums) {
    map<int, int> m;
    vector<int> unique_nums;
    for (auto num : nums) {
      auto && t = m.insert(pair<int, int>(num, 0));
      if (t.second) unique_nums.push_back(num);
      ++t.first->second;
    }

    vector<vector<int>> ans;
    for (auto num1 : unique_nums) {
      for (auto num2 : unique_nums) {
        if ((num1 > num2) || ((num1 == num2) && (m[num1] < 2))) continue;
        auto num3 = -num1 - num2;
        if (num2 > num3) continue;
        auto && t = m.find(num3);
        if (t == m.end()) continue;
        if (num1 == num2) {
          if ((num2 == num3) && (t->second < 3)) continue;
        } else {
          if ((num2 == num3) && (t->second < 2)) continue;
        }
        ans.push_back({ num1, num2, num3 });
      }
    }

    return ans;
  }
};

Solution s;

class TestCase {
public:
  TestCase() {
    cout << "P0015: 3Sum." << endl;

    auto && f = testAnswer<vector<vector<int>>, vector<int>>;
    f({}, {});
    f({}, { 0 });
    f({}, { 0, 0 });
    f({}, { 0, 0, 1 });
    f({ { 0, 0, 0 } }, { 0, 0, 0 });
    f({ { -1, -1, 2 } }, { -1, -1, -1, 2 });
    f({ { -1, 0, 1 }, { -1, -1, 2 } }, { -1, 0, 1, 2, -1, -4 });

    cout << "Point: " << (Q - X) << "/" << Q << endl;
  }

private:
  // template <typename _Ty>
  // static bool compareAnswer(_Ty const & l, _Ty const & r) { return l == r; }
  static bool compareAnswer(vector<vector<int>> & l, vector<vector<int>> & r) {
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    return l == r;
  }

  template <typename _Ans, typename... _Types>
  static void testAnswer(_Ans && ans, _Types &&... args) {
    _Ans && _ans = s.threeSum(const_cast<_Types &>(args)...);

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
