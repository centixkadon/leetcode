
#include "stl.hpp"

using namespace std;

int main() {
  cout << "arithmetic" << endl;
  write(cout << "int", 1) << endl;
  write(cout << "ull", 1ull) << endl;
  write(cout << "char", '1') << endl;
  write(cout << "float", 1.2f) << endl;
  write(cout << "double", 1.23456) << endl;
  cout << endl;

  cout << "element" << endl;
  write(cout << "string", string("123 45\n6 7890")) << endl;
  write(cout << "pair", make_pair(1.2, 3)) << endl;
  write(cout << "tuple", make_tuple()) << endl;
  write(cout << "tuple", make_tuple(1, '2', 3.4, string("5"))) << endl;
  cout << endl;

  cout << "container" << endl;
  write(cout << "array", array<int, 3>{ 5, 1, 9 }) << endl;
  write(cout << "deque", deque<int>{ 5, 1, 9 }) << endl;
  write(cout << "f_list", forward_list<int>{ 5, 1, 9 }) << endl;
  write(cout << "list", list<int>{ 5, 1, 9 }) << endl;
  write(cout << "map", map<int, int>{ { 5, 4 }, { 1, 7 }, { 9, 2 } }) << endl;
  write(cout << "m_map", multimap<int, int>{ { 5, 4 }, { 1, 7 }, { 9, 2 }, { 5, 6 }, { 1, 3 }, { 9, 8 } }) << endl;
  write(cout << "set", set<int>{ 5, 1, 9 }) << endl;
  write(cout << "u_map", unordered_map<int, int>{ { 5, 4 }, { 1, 7 }, { 9, 2 } }) << endl;
  write(cout << "u_set", unordered_set<int>{ 5, 1, 9 }) << endl;
  write(cout << "vector", vector<int>{ 5, 1, 9 }) << endl;
  cout << endl;

  return 0;
}
