#include <assert.h>
#include <fstream>
#include <iostream>
using namespace std;

string read_file(char *filename) {

  string s;

  ifstream output_file;

  output_file.open(filename);

  if (output_file.is_open()) {
    output_file >> s;
    output_file.close();
  } else {
    cerr << "Unable to open " << filename << endl;
  }

  return s;
}

int main(int argc, char **argv) {

  if (argc < 3) {
    cerr << "File paths are not present" << endl;

    return 1;
  }

  char *first_file = argv[1];
  char *second_file = argv[2];

  string first_file_contents = read_file(first_file);
  string second_file_contents = read_file(second_file);

  // check if both the file contents are same
  assert(first_file_contents == second_file_contents);
  return 0;
}
