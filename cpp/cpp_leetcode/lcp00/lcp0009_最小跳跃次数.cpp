
#include "leetcode.hpp"

class Solution {
public:
  int minJump(vector<int> & jump) {
    vector<bool> t(jump.size(), true);

    struct Elem {
      size_t i;
      int count;
    };
    deque<Elem> dq;
    dq.push_back({ 0, 0 });

    size_t i = 0;
    while (!dq.empty()) {
      auto e = dq.front();
      dq.pop_front();

      for (; i < e.i; ++i) {
        if (t[i]) {
          dq.push_back({ i, e.count + 1 });
          t[i] = false;
        }
      }
      size_t j = e.i + jump[e.i];
      if (j >= jump.size()) return e.count + 1;
      if (t[j]) {
        dq.push_back({ j, e.count + 1 });
        t[j] = false;
      }
    }

    return -1;
  }
};

int main() {
  {
    auto check = solve(&Solution::minJump);
    check(1, { 1 });
    check(1, { 10 });
    check(4, { 1, 1, 1, 1 });
    check(2, { 1, 5, 1, 1, 1, 1 });
    check(3, { 2, 5, 1, 1, 1, 1 });
    check(3, { 3, 5, 1, 1, 1, 1 });
    check(5, { 2, 5, 1, 1, 1, 5, 1, 1, 1, 1 });
    check(4, { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    check(3, { 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 1 });
    check(4, { 3, 6, 7, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1 });
    check(100000, vector<int>(100000, 1));
  }
  return 0;
}

Settings;
