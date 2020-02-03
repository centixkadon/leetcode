
#include "leetcode.hpp"

class Solution {
public:
  size_t run(size_t value) {
    cerr << "value: " << value << endl;
    return value;
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::run);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check(1, 1);
    check(2, 2);
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
