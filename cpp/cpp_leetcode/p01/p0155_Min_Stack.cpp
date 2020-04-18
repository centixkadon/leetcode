
#include "leetcode.hpp"

class MinStack {
public:
  inline MinStack() : _s(1, numeric_limits<int>::max()) { _m.push(0); }

  inline void push(int x) {
    if (x < getMin()) _m.push(_s.size());
    _s.push_back(x);
  }

  inline void pop() {
    _s.pop_back();
    if (_s.size() == _m.top()) _m.pop();
  }

  inline int top() { return _s.back(); }

  inline int getMin() { return _s[_m.top()]; }

private:
  vector<int> _s;
  stack<size_t> _m;
};

class Solution {
public:
  vector<int> run(vector<vector<int>> commands) {
    vector<int> ans;
    auto minStack = new MinStack();
    for (auto & command : commands) {
      switch (command[0]) {
      case 0:
        minStack->push(command[1]);
        break;
      case 1:
        minStack->pop();
        break;
      case 2:
        ans.push_back(minStack->top());
        break;
      case 3:
        ans.push_back(minStack->getMin());
        break;
      }
    }
    return move(ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::run);
    check({ -3, 0, -2 }, { { 0, -2 }, { 0, 0 }, { 0, -3 }, { 3 }, { 1 }, { 2 }, { 3 } });
  }
  return 0;
}

Settings;
