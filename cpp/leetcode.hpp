
#include <algorithm>
#include <bitset>
#include <chrono>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <numeric>
#include <random>
#include <ratio>
#include <tuple>
#include <utility>
#include <valarray>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace std {

template <typename _Elem, typename _Traits, typename _Ty, typename _Alloc, template <typename, typename> typename _Container>
basic_ostream<_Elem, _Traits> & operator<<(basic_ostream<_Elem, _Traits> & _Ostr, _Container<_Ty, _Alloc> const & _Right) {
  _Ostr << "[";
  for (auto const & _Val : _Right) { _Ostr << " " << _Val; }
  _Ostr << " ]";
  return _Ostr;
}

} // namespace std

using namespace std;

template <typename _Elem, typename _Traits, typename _Ty>
basic_ostream<_Elem, _Traits> & printParameterPacks(basic_ostream<_Elem, _Traits> & _Ostr, _Ty && _Arg) { return _Ostr << _Arg; }

template <typename _Elem, typename _Traits, typename _Ty, typename... _Types>
basic_ostream<_Elem, _Traits> & printParameterPacks(basic_ostream<_Elem, _Traits> & _Ostr, _Ty && _Arg, _Types &&... _Args) { return printParameterPacks(_Ostr << _Arg << ", ", _Args...); }

size_t X = 0, Q = 0;
