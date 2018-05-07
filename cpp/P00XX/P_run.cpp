
#include "leetcode.hpp"

int main(int argc, char ** argv) {
  string s = argv[0];
  s = s.substr(0, s.size() - 4);

  for (size_t i = 0; i != (size_t)-1; ++i) {
    string fs = s + (static_cast<stringstream &>(stringstream() << setw(4) << setfill('0') << i).str());
    if (ifstream(fs)) {
      int i = system(fs.c_str());
      cout << endl;
    } else
      break;
  }

  return 0;
}
