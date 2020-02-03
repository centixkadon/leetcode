
#include "leetcode.hpp"

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> v(n);
    v.back() = 1;
    for (size_t i = v.size() - 2; i < v.size() - 1; --i) v[i] = v[i + 1] * (v.size() - i);
    for (size_t i = 0; i < v.size() - 1; ++i) v[i] = (k - 1) % v[i] / v[i + 1];
    v.back() = 0;

    list<int> l;
    for (size_t i = 0; i < v.size(); ++i) l.push_back(i);

    for (size_t i = 0; i < v.size(); ++i) {
      auto it = l.begin();
      for (int j = 0; j < v[i]; ++j) ++it;
      v[i] = *it + '1';
      l.erase(it);
    }

    return move(string(v.begin(), v.end()));
  }
};

int main() {
  {
    auto check = solve(&Solution::getPermutation);
    check("123", 3, 1);
    check("132", 3, 2);
    check("213", 3, 3);
    check("231", 3, 4);
    check("312", 3, 5);
    check("321", 3, 6);
    check("1", 1, 1);
  }
  return 0;
}

Settings;
