#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::istream;
using std::stringstream;

/**
 * Everything you type as input gets ouputted as soon as you hit the <enter> key
 */
void newCat(istream &input);

/**
 * outputs the files that you pass as arguments, will exit if one of the files
 * dosn't exist
 * @param argc number of arguments
 * @param argv file names that have been passed
 */
void newCat(int argc, char* argv[]);

int main(int argc, char* argv[]) {
  newCat(argc, argv);
  return 0;
}

void newCat(istream &input) {
  string string_cout;

  while (!cin.eof()) {
    getline(input, string_cout);
    cout << string_cout << endl;
  }
}

void newCat(int argc, char* argv[]) {
  string string_cout;
  string compare_string;
  stringstream ss;

  for (int i = 1; i < argc; ++i) {
    ss << argv[i];
    ss >> compare_string;
    ifstream fin(compare_string);

    if (fin.fail()) {
      exit(1);
    }
    ss.clear();
  }

  for (int i = 1; i < argc; ++i) {
    ss << argv[i];
    ss >> compare_string;
    ifstream fin(compare_string);

    while (!fin.eof()) {
      getline(fin, string_cout);
      cout << string_cout << endl;
    }
    ss.clear();
  }
}
