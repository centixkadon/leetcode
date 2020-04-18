
#include "leetcode.hpp"

class LRUCache {
public:
  LRUCache(int capacity) : _capacity(capacity), _id(0) {}

  int get(int key) {
    auto it = _map.find(key);
    if (it == _map.end()) {
      return -1;
    } else {
      auto value = it->second->second;
      _list.erase(it->second);
      _list.push_back({ key, value });
      it->second = --_list.end();
      return value;
    }
  }

  void put(int key, int value) {
    auto it = _map.find(key);
    if (it == _map.end()) {
      if (_list.size() == _capacity) {
        _map.erase(_list.front().first);
        _list.pop_front();
      }
      _list.push_back({ key, value });
      _map[key] = --_list.end();
    } else {
      _list.erase(it->second);
      _list.push_back({ key, value });
      it->second = --_list.end();
    }
  }

private:
  size_t _capacity;
  size_t _id;
  list<pair<int, int>> _list;
  unordered_map<int, list<pair<int, int>>::const_iterator> _map;
};

class Solution {
public:
  vector<int> run(int capacity, vector<vector<int>> & commands) {
    vector<int> ans;
    LRUCache * cache = new LRUCache(capacity);
    for (auto & command : commands) {
      switch (command.size()) {
      case 1:
        ans.push_back(cache->get(command[0]));
        break;
      case 2:
        cache->put(command[0], command[1]);
        break;
      }
    }
    delete cache;
    cache = nullptr;
    return move(ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::run);
    check({ 1, -1, -1, 3, 4 }, 2, { { 1, 1 }, { 2, 2 }, { 1 }, { 3, 3 }, { 2 }, { 4, 4 }, { 1 }, { 3 }, { 4 } });
    check({ -1, 3 }, 2, { { 2, 1 }, { 1, 1 }, { 2, 3 }, { 4, 1 }, { 1 }, { 2 } });
  }
  return 0;
}

Settings;
