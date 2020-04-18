
#include "leetcode.hpp"

class Trie {
public:
  Trie() { _t.setStart(); }

  void insert(string word) {
    auto p = &_t;
    for (auto c : word) {
      p = &(*p)[c];
      p->setStart();
    }
    p->setEnd();
  }

  bool search(string word) {
    auto p = &_t;
    for (auto c : word) {
      if (p->empty()) return false;
      p = &(*p)[c];
    }
    return p->getEnd();
  }

  bool startsWith(string prefix) {
    auto p = &_t;
    for (auto c : prefix) {
      if (p->empty()) return false;
      p = &(*p)[c];
    }
    return p->getStart();
  }

private:
  class TrieNode {
  public:
    TrieNode() : _start(false), _end(false) {}

    TrieNode & operator[](char c) {
      if (empty()) _children.resize(26);
      return _children[c - 'a'];
    }

    inline bool empty() const { return _children.empty(); }

    inline void setStart() { _start = true; }
    inline void setEnd() { _end = true; }
    inline bool getStart() const { return _start; }
    inline bool getEnd() const { return _end; }

  private:
    vector<TrieNode> _children;
    bool _start;
    bool _end;
  };

  TrieNode _t;
};

class Solution {
public:
  vector<bool> run(vector<pair<size_t, string>> commands) {
    vector<bool> ans;
    auto trie = new Trie();
    for (auto & command : commands) {
      switch (command.first) {
      case 0:
        trie->insert(command.second);
        break;
      case 1:
        ans.push_back(trie->search(command.second));
        break;
      case 2:
        ans.push_back(trie->startsWith(command.second));
        break;
      }
    }
    return move(ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::run);
    check({ true, false, false, true, true, true }, { { 0, "abc" }, { 1, "abc" }, { 1, "ab" }, { 1, "a" }, { 2, "abc" }, { 2, "ab" }, { 2, "a" } });
    check({ true, true, false, true, true, true }, { { 0, "abc" }, { 0, "ab" }, { 1, "abc" }, { 1, "ab" }, { 1, "a" }, { 2, "abc" }, { 2, "ab" }, { 2, "a" } });
    check({ true, false, true, true, true, true }, { { 0, "abc" }, { 0, "a" }, { 1, "abc" }, { 1, "ab" }, { 1, "a" }, { 2, "abc" }, { 2, "ab" }, { 2, "a" } });
    check({ false, false, false, false, false, false }, { { 0, "b" }, { 1, "abc" }, { 1, "ab" }, { 1, "a" }, { 2, "abc" }, { 2, "ab" }, { 2, "a" } });
  }
  return 0;
}

Settings;
