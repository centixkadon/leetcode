
#include "leetcode.hpp"

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> & strs) {
    unordered_map<size_t, vector<string>> m;
    for (auto & str : strs) {
      m[getHash(str)].emplace_back(move(str));
    }

    vector<vector<string>> ans;
    ans.reserve(m.size());
    for (auto & p : m) ans.emplace_back(move(p.second));
    return move(ans);
  }
  vector<vector<string>> groupAnagramsCheck(vector<string> & strs) {
    auto && ans = groupAnagrams(strs);
    for (auto & ans : ans) sort(ans.begin(), ans.end());
    sort(ans.begin(), ans.end());
    return move(ans);
  }

private:
  static size_t getHash(string const & _Keyval) {
    vector<uint8_t> v(numeric_limits<uint8_t>::max(), 0);
    for (auto c : _Keyval) ++v[c];

    size_t _Val = _FNV_offset_basis;
    for (size_t i = 0; i < v.size(); ++i) {
      _Val ^= size_t(v[i]);
      _Val *= _FNV_prime;
    }
    return _Val;
  }

  static size_t const _FNV_offset_basis = 14695981039346656037ULL;
  static size_t const _FNV_prime = 1099511628211ULL;
};

int main() {
  {
    auto check = solve(&Solution::groupAnagramsCheck);
    check({ { "ate", "eat", "tea" }, { "bat" }, { "nat", "tan" } }, { "eat", "tea", "tan", "ate", "nat", "bat" });
  }
  return 0;
}

Settings;
