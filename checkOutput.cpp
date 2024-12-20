#include <assert.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> read_lines(char *filename) {
  vector<string> lines;

  ifstream output_file;

  output_file.open(filename);

  if (output_file.is_open()) {
    string line;
    while (getline(output_file, line))
      lines.push_back(line);

    output_file.close();
  } else {
    cerr << "Unable to open " << filename << endl;
  }

  return lines;
}

int main(int argc, char **argv) {

  if (argc < 3) {
    cerr << "File paths are not present" << endl;

    return 1;
  }

  char *first_file = argv[1];
  char *second_file = argv[2];

  vector<string> first_file_contents = read_lines(first_file);
  vector<string> second_file_contents = read_lines(second_file);

  assert(first_file_contents == second_file_contents);

  return 0;
}
