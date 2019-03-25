
#include "leetcode.hpp"

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    vector<size_t> ans(num1.size() + num2.size(), 0);
    for (size_t i = 0; i < num1.size(); ++i)
      for (size_t j = 0; j < num2.size(); ++j) {
        ans[i + j] += (num1[num1.size() - 1 - i] - '0') * (num2[num2.size() - 1 - j] - '0');
      }
    for (size_t i = 0; i < ans.size() - 1; ++i) {
      ans[i + 1] += ans[i] / 10;
      ans[i] %= 10;
    }
    while (ans.back() == 0) ans.pop_back();
    for (auto & c : ans) c += '0';
    return string(ans.rbegin(), ans.rend());
  }
};

int main() {
  {
    auto check = solve(&Solution::multiply);
    check("6", "2", "3");
    check("56088", "123", "456");
    check("998001", "999", "999");
  }
  return 0;
}

Settings;
