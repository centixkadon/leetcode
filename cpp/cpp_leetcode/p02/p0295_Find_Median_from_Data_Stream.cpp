
#include "leetcode.hpp"

template <typename _Ty, typename _Pr = less<_Ty>>
class priority_counting_queue {
public:
  typedef priority_counting_queue<_Ty, _Pr> _Myt;
  typedef _Ty value_type;
  typedef typename vector<size_t>::size_type size_type;

  priority_counting_queue(value_type l, size_t _Count) : _l(l), _c(_Count, 0), _sz(0) {}

  void push(value_type const & _Val) {
    ++_c[_Val - _l];
    if (!_sz) {
      _v = _Val;
    } else {
      _v = max(_Val, _v, _comp);
    }
    ++_sz;
  }

  void pop() {
    --_c[_v - _l];
    --_sz;
    if (_sz) {
      while (!_c[_v - _l]) _v = min(_v - 1, _v + 1, _comp);
    }
  }

  inline value_type top() const { return _v; }
  inline size_type size() const { return _sz; }
  inline bool empty() const { return size() == 0; }

  inline value_type lower_bound() const { return _l; }
  inline value_type upper_bound() const { return _l + _c.size() - 1; }

private:
  value_type _l;
  vector<size_t> _c;
  size_t _sz;
  value_type _v;
  _Pr _comp;
};

template <typename _Ty, typename _Container = vector<_Ty>, typename _Pr = less<typename _Container::value_type>>
class priority_queue_with_counting {
public:
  typedef priority_queue_with_counting<_Ty, _Container, _Pr> _Myt;
  typedef _Ty value_type;
  typedef typename vector<size_t>::size_type size_type;

  priority_queue_with_counting(value_type l, size_t d) : _cs(l, d) {}

  void push(value_type const & _Val) {
    if (_comp(_Val, _cs.lower_bound()) && _comp(_Val, _cs.upper_bound())) {
      _xs.push(_Val);
    } else if (_comp(_cs.lower_bound(), _Val) && _comp(_cs.upper_bound(), _Val)) {
      _ys.push(_Val);
    } else {
      _cs.push(_Val);
    }
  }

  void pop() {
    if (!_ys.empty()) {
      _ys.pop();
    } else if (!_cs.empty()) {
      _cs.pop();
    } else {
      _xs.pop();
    }
  }

  value_type top() const {
    if (!_ys.empty()) return _ys.top();
    if (!_cs.empty()) return _cs.top();
    return _xs.top();
  }

  inline size_type size() const { return _xs.size() + _ys.size() + _cs.size(); }
  inline bool empty() const { return size() == 0; }

private:
  priority_queue<_Ty, _Container, _Pr> _xs, _ys;
  priority_counting_queue<_Ty, _Pr> _cs;
  _Pr _comp;
};

class MedianFinder {
public:
  MedianFinder() : _xs(_l, _d), _ys(_l, _d) {}

  void addNum(int num) {
    if (_xs.empty() || num < _xs.top()) {
      if (_xs.size() != _ys.size()) {
        _ys.push(_xs.top());
        _xs.pop();
      }
      _xs.push(num);
    } else if (_ys.empty() || num < _ys.top()) {
      if (_xs.size() == _ys.size())
        _xs.push(num);
      else
        _ys.push(num);
    } else {
      if (_xs.size() == _ys.size()) {
        _xs.push(_ys.top());
        _ys.pop();
      }
      _ys.push(num);
    }
  }

  double findMedian() {
    if (_xs.size() == _ys.size()) return static_cast<double>(_xs.top() + _ys.top()) / 2.0;
    return _xs.top();
  }

private:
  // priority_queue<int> _xs;
  // priority_queue<int, vector<int>, greater<int>> _ys;
  // priority_counting_queue<int> _xs;
  // priority_counting_queue<int, greater<int>> _ys;
  priority_queue_with_counting<int> _xs;
  priority_queue_with_counting<int, vector<int>, greater<int>> _ys;

  static int constexpr _l = 0;
  static size_t constexpr _d = 101;
};

class Solution {
public:
  vector<double> run(vector<int> & commands) {
    vector<double> ans;
    MedianFinder * medianFinder = new MedianFinder();
    for (auto command : commands) {
      medianFinder->addNum(command);
      ans.push_back(medianFinder->findMedian());
    }
    return move(ans);
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::run);
    check({ 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    cerr.rdbuf(cerr_buffer);
    check({ 40.0, 26.0, 16.0, 15.0 }, { 40, 12, 16, 14 });
    cerr.rdbuf(nullptr);
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
