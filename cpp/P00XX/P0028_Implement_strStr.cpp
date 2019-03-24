
#include "leetcode.hpp"

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) return -1;
    for (size_t i = 0; i <= haystack.size() - needle.size(); ++i) {
      bool t = true;
      for (size_t j = 0; j < needle.size(); ++j) {
        if (haystack[i + j] != needle[j]) {
          t = false;
          break;
        }
      }
      if (t) return i;
    }
    return -1;
  }
};

int main() {
  {
    auto check = solve(&Solution::strStr);
    check(0, "", "");
    check(-1, "", "a");
    check(-1, "a", "aa");
    check(2, "hello", "ll");
    check(-1, "aaaaa", "bba");
    check(0, "aaaaa", "aa");
    check(4, "aaaab", "b");
  }
  return 0;
}

Settings;
