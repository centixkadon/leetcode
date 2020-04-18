
#include "leetcode.hpp"

class Solution {
public:
  size_t run(size_t value) {
    cerr << "debug: " << value << endl;
    return value;
  }
};

int main() {
  {
    auto check = solve(&Solution::run);
    check(1, 1);
    check.debug(2, 2);
  }
  return 0;
}

Settings;
