
#include "leetcode.hpp"

class Solution {
public:
  vector<int> getTriggerTime(vector<vector<int>> & increase, vector<vector<int>> & requirements) {
    vector<vector<int>> CRH(3, vector<int>(increase.size() + 1, 0));

    for (size_t i = 0; i < increase.size(); ++i) {
      for (size_t j = 0; j < increase[i].size(); ++j) {
        CRH[j][i + 1] = CRH[j][i] + increase[i][j];
      }
    }

    vector<int> ans(requirements.size());
    for (size_t i = 0; i < requirements.size(); ++i) {
      size_t k = 0;
      for (size_t j = 0; j < requirements[i].size(); ++j) {
        size_t kk = lower_bound(CRH[j].begin(), CRH[j].end(), requirements[i][j]) - CRH[j].begin();
        k = max(k, kk);
      }
      if (k == increase.size() + 1)
        ans[i] = -1;
      else
        ans[i] = int(k);
    }

    return move(ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::getTriggerTime);
    check({ -1, 4, 3, 3, 3 }, { { 0, 4, 5 }, { 4, 8, 8 }, { 8, 6, 1 }, { 10, 10, 0 } }, { { 12, 11, 16 }, { 20, 2, 6 }, { 9, 2, 6 }, { 10, 18, 3 }, { 8, 14, 9 } });
    check({ 0 }, { { 1, 1, 1 } }, { { 0, 0, 0 } });
  }
  return 0;
}

Settings;
