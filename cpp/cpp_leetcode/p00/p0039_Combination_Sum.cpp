
#include "leetcode.hpp"

class Solution {
public:
  void combinationSumDfs(vector<vector<int>> & answers, vector<int> & answer, vector<int> & candidates, int target, size_t i = 0) {
    if (i == candidates.size()) {
      if (target == 0) answers.push_back(answer);
      return;
    }

    auto sz = answer.size();
    for (int j = 0; candidates[i] * j <= target; ++j) {
      combinationSumDfs(answers, answer, candidates, target - candidates[i] * j, i + 1);
      answer.push_back(candidates[i]);
    }
    answer.resize(sz);
  }
  vector<vector<int>> combinationSum(vector<int> & candidates, int target) {
    if (candidates.empty()) return {};

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> answers;
    vector<int> answer;
    answer.reserve(target / candidates[0]);
    combinationSumDfs(answers, answer, candidates, target);
    return move(answers);
  }
};

int main() {
  {
    auto check = solve_unordered(&Solution::combinationSum);
    check({ { 7 }, { 2, 2, 3 } }, { 2, 3, 6, 7 }, 7);
    check({ { 2, 2, 2, 2 }, { 2, 3, 3 }, { 3, 5 } }, { 2, 3, 5 }, 8);
    check({}, {}, 1);
    check({ { 1, 1, 1 } }, { 1 }, 3);
  }
  return 0;
}

Settings;
