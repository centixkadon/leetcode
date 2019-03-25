
#include "leetcode.hpp"

int main(int argc, char ** argv) {
  string s = argv[0];
  s = s.substr(0, s.find_last_of('/') + 1) + "p";

  size_t index_begin = 0, index_end = -1;
  if (argc > 1) stringstream(argv[1]) >> index_begin;
  if (argc > 2) stringstream(argv[2]) >> index_end;

  cout << "leetcode run all" << endl;
  cout << endl;

  for (size_t i = index_begin; i != index_end; ++i) {
    string fs = s + (dynamic_cast<stringstream &>(stringstream() << setw(4) << setfill('0') << i).str());
    if (ifstream(fs)) {
      if (system(fs.c_str()) != 0) break;
      cout << endl;
    } else
      break;
  }

  return 0;
}
