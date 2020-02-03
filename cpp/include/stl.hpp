
#pragma once

#if 0
// C compatibility headers
#include <cassert>   //
#include <cctype>    //
#include <cerrno>    //
#include <cfenv>     // since C++11
#include <cfloat>    //
#include <cinttypes> // since C++11
#include <climits>   //
#include <clocale>   //
#include <cmath>     //
#include <csetjmp>   //
#include <csignal>   //
#include <cstdarg>   //
#include <cstddef>   //
#include <cstdint>   // since C++11
#include <cstdio>    //
#include <cstdlib>   //
#include <cstring>   //
#include <ctime>     //
#include <cuchar>    // since C++11
#include <cwchar>    //
#include <cwctype>   //
#endif

// Utilities library
#include <bitset>           //
#include <chrono>           // since C++11
#include <functional>       //
#include <initializer_list> // since C++11
#include <tuple>            // since C++11
#include <type_traits>      // since C++11
#include <typeindex>        // since C++11
#include <typeinfo>         //
#include <utility>          //
// #include <any>              // since C++17
// #include <optional>         // since C++17
// #include <variant>          // since C++17

// Dynamic memory management
#include <memory>           //
#include <new>              //
#include <scoped_allocator> // since C++11
// #include <memory_resource>  // since C++17

// Numeric limits
#include <limits> //

// Error handling
#include <exception>    //
#include <stdexcept>    //
#include <system_error> // since C++11

// Strings library
#include <string> //
// #include <charconv>    // since C++17
// #include <string_view> // since C++17

// Containers library
#include <array>         // since C++11
#include <deque>         //
#include <forward_list>  // since C++11
#include <list>          //
#include <map>           //
#include <set>           //
#include <unordered_map> // since C++11
#include <unordered_set> // since C++11
#include <vector>        //

// Adapters library
#include <queue> //
#include <stack> //

// Iterators library
#include <iterator> //

// Algorithms library
#include <algorithm> //
// #include <execution> // since C++17

// Numerics library
#include <complex>  //
#include <numeric>  //
#include <random>   // since C++11
#include <ratio>    // since C++11
#include <valarray> //

// Input/output library
#include <fstream>   //
#include <iomanip>   //
#include <ios>       //
#include <iosfwd>    //
#include <iostream>  //
#include <istream>   //
#include <ostream>   //
#include <sstream>   //
#include <streambuf> //

// Localization library
#include <locale> //

// Regular Expressions library
#include <regex> // since C++11

// Atomic Operations library
#include <atomic> // since C++11

// Thread support library
#include <condition_variable> // since C++11
#include <future>             // since C++11
#include <mutex>              // since C++11
#include <shared_mutex>       // since C++14
#include <thread>             // since C++11

// Filesystem library
// #include <filesystem> // since C++17



struct arithmetic_data_tag {};
struct element_data_tag {};
struct container_data_tag {};
struct adapter_data_tag {};

struct arithmetic_data_traits {
  using data_category = arithmetic_data_tag;
};
struct element_data_traits {
  using data_category = element_data_tag;
};
struct container_data_traits {
  using data_category = container_data_tag;
};
struct adapter_data_traits {
  using data_category = adapter_data_tag;
};

template <typename _Ty>
struct data_traits : std::conditional_t<std::is_arithmetic<_Ty>::value, arithmetic_data_traits, element_data_traits> {};

template <typename _Ty, size_t _Size>
struct data_traits<std::array<_Ty, _Size>> : container_data_traits {};
template <typename _Ty, typename _Alloc>
struct data_traits<std::deque<_Ty, _Alloc>> : container_data_traits {};
template <typename _Ty, typename _Alloc>
struct data_traits<std::forward_list<_Ty, _Alloc>> : container_data_traits {};
template <typename _Ty, typename _Alloc>
struct data_traits<std::list<_Ty, _Alloc>> : container_data_traits {};
template <typename _Kty, typename _Ty, typename _Pr, typename _Alloc>
struct data_traits<std::map<_Kty, _Ty, _Pr, _Alloc>> : container_data_traits {};
template <typename _Kty, typename _Ty, typename _Pr, typename _Alloc>
struct data_traits<std::multimap<_Kty, _Ty, _Pr, _Alloc>> : container_data_traits {};
template <typename _Kty, typename _Pr, typename _Alloc>
struct data_traits<std::set<_Kty, _Pr, _Alloc>> : container_data_traits {};
template <typename _Kty, typename _Pr, typename _Alloc>
struct data_traits<std::multiset<_Kty, _Pr, _Alloc>> : container_data_traits {};
template <typename _Kty, typename _Ty, typename _Hasher, typename _Keyeq, typename _Alloc>
struct data_traits<std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc>> : container_data_traits {};
template <typename _Kty, typename _Hasher, typename _Keyeq, typename _Alloc>
struct data_traits<std::unordered_set<_Kty, _Hasher, _Keyeq, _Alloc>> : container_data_traits {};
template <typename _Ty, typename _Alloc>
struct data_traits<std::vector<_Ty, std::allocator<_Alloc>>> : container_data_traits {};

template <typename _Ty, typename _Container>
struct data_traits<std::queue<_Ty, _Container>> : adapter_data_traits {};
template <typename _Ty, typename _Container, typename _Pr>
struct data_traits<std::priority_queue<_Ty, _Container, _Pr>> : adapter_data_traits {};
template <typename _Ty, typename _Container>
struct data_traits<std::stack<_Ty, _Container>> : adapter_data_traits {};


template <typename _Elem, typename _Traits, typename... _Types, size_t... _Vals>
inline std::basic_ostream<_Elem, _Traits> & _write2(std::basic_ostream<_Elem, _Traits> & _Ostr, std::tuple<_Types...> const & _Arg, std::index_sequence<_Vals...>);
template <typename _Elem, typename _Traits, typename _Ty, typename _Tag>
inline std::basic_ostream<_Elem, _Traits> & _write1(std::basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, _Tag);
template <typename _Elem, typename _Traits>
inline std::basic_ostream<_Elem, _Traits> & write(std::basic_ostream<_Elem, _Traits> & _Ostr);
template <typename _Elem, typename _Traits, typename _Ty>
inline std::basic_ostream<_Elem, _Traits> & write(std::basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg);
template <typename _Elem, typename _Traits, typename _Ty, typename... _Types>
inline std::basic_ostream<_Elem, _Traits> & write(std::basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, _Types const &... _Args);

template <typename _Elem, typename _Traits, typename... _Types, size_t... _Vals>
inline std::basic_ostream<_Elem, _Traits> & _write2(std::basic_ostream<_Elem, _Traits> & _Ostr, std::tuple<_Types...> const & _Arg, std::index_sequence<_Vals...>) {
  return write(_Ostr << "(", std::get<_Vals>(_Arg)...) << ")";
}

template <typename _Elem, typename _Traits, typename _Ty>
inline std::basic_ostream<_Elem, _Traits> & _write1(std::basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, arithmetic_data_tag) {
  return _Ostr << _Arg;
}
template <typename _Elem, typename _Traits, typename _Alloc>
inline std::basic_ostream<_Elem, _Traits> & _write1(std::basic_ostream<_Elem, _Traits> & _Ostr, std::basic_string<_Elem, _Traits, _Alloc> const & _Arg, element_data_tag) {
  std::basic_string<_Elem, _Traits, _Alloc> _Str = _Arg;
  std::replace(_Str.begin(), _Str.end(), '\n', '`');
  return _Ostr << '"' << _Str << '"';
}
template <typename _Elem, typename _Traits, typename _Ty1, typename _Ty2>
inline std::basic_ostream<_Elem, _Traits> & _write1(std::basic_ostream<_Elem, _Traits> & _Ostr, std::pair<_Ty1, _Ty2> const & _Arg, element_data_tag) {
  return write(write(_Ostr << "<", _Arg.first) << " ", _Arg.second) << ">";
}
template <typename _Elem, typename _Traits, typename... _Types>
inline std::basic_ostream<_Elem, _Traits> & _write1(std::basic_ostream<_Elem, _Traits> & _Ostr, std::tuple<_Types...> const & _Arg, element_data_tag) {
  return _write2(_Ostr, _Arg, std::index_sequence_for<_Types...>());
}
template <typename _Elem, typename _Traits, typename _Ty>
inline std::basic_ostream<_Elem, _Traits> & _write1(std::basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, element_data_tag) {
  return _Ostr << "e(" << _Arg << ")";
}
template <typename _Elem, typename _Traits, typename _Ty>
inline std::basic_ostream<_Elem, _Traits> & _write1(std::basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, container_data_tag) {
  _Ostr << "[ ";
  for (auto const & _Val : _Arg) write(_Ostr, _Val) << " ";
  return _Ostr << "]";
}

template <typename _Elem, typename _Traits>
inline std::basic_ostream<_Elem, _Traits> & write(std::basic_ostream<_Elem, _Traits> & _Ostr) {
  return _Ostr;
}
template <typename _Elem, typename _Traits, typename _Ty>
inline std::basic_ostream<_Elem, _Traits> & write(std::basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg) {
  return _write1(_Ostr, _Arg, typename data_traits<_Ty>::data_category());
}
template <typename _Elem, typename _Traits, typename _Ty, typename... _Types>
inline std::basic_ostream<_Elem, _Traits> & write(std::basic_ostream<_Elem, _Traits> & _Ostr, _Ty const & _Arg, _Types const &... _Args) {
  return write(write(_Ostr, _Arg) << " ", _Args...);
}
