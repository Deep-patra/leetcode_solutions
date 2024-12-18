#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

  if (argc == 1)
    cout << "No arguments are provided" << endl;

  for (int i = 0; i < argc; i++) {
    char *str = argv[i];
    cout << str << endl;
  }

  return 0;
}
