#include <iostream>
#include <string>
#include <vector>
using namespace std;

// INFO: Beats 100% runtime 0ms
string remove_occurences(string s, string part) {
  string result = s;

  size_t pos = result.find(part);

  while (pos != string::npos) {
    result = result.substr(0, pos) + result.substr(pos + part.length());
    pos = result.find(part);
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s, part;
    cin >> s >> part;

    string result = remove_occurences(s, part);
    cout << result << '\n';
  }

  return 0;
}
