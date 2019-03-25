
#include "leetcode.hpp"

class Solution {
public:
  void combinationSum2Dfs(vector<vector<int>> & answers, vector<int> & answer, vector<int> & candidatesUnique, vector<size_t> & candidatesCount, int target, size_t i = 0) {
    if (i == candidatesUnique.size()) {
      if (target == 0) answers.push_back(answer);
      return;
    }

    auto sz = answer.size();
    for (int j = 0; j <= candidatesCount[i] && candidatesUnique[i] * j <= target; ++j) {
      combinationSum2Dfs(answers, answer, candidatesUnique, candidatesCount, target - candidatesUnique[i] * j, i + 1);
      answer.push_back(candidatesUnique[i]);
    }
    answer.resize(sz);
  }
  vector<vector<int>> combinationSum2(vector<int> & candidates, int target) {
    if (candidates.empty()) return {};

    sort(candidates.begin(), candidates.end());
    vector<int> candidatesUnique;
    candidatesUnique.reserve(candidates.size());
    vector<size_t> candidatesCount;
    candidatesCount.reserve(candidates.size());
    for (auto candidate : candidates) {
      if (candidatesUnique.empty() || candidatesUnique.back() != candidate) {
        candidatesUnique.push_back(candidate);
        candidatesCount.push_back(1);
      } else {
        ++candidatesCount.back();
      }
    }

    vector<vector<int>> answers;
    vector<int> answer;
    answer.reserve(target / candidates[0]);
    combinationSum2Dfs(answers, answer, candidatesUnique, candidatesCount, target);
    return move(answers);
  }
};

int main() {
  {
    auto check = solve_unordered(&Solution::combinationSum2);
    check({ { 1, 7 }, { 1, 2, 5 }, { 2, 6 }, { 1, 1, 6 } }, { 10, 1, 2, 7, 6, 1, 5 }, 8);
    check({ { 1, 2, 2 }, { 5 } }, { 2, 5, 2, 1, 2 }, 5);
  }
  return 0;
}

Settings;
