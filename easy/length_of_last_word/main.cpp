#include <iostream>
#include <string>
using namespace std;

int length_of_last_word(string s) {
  string last_word = "";

  int i = s.length() - 1;
  while (i >= 0) {

    if (s[i] != ' ') {
      last_word = s[i] + last_word;
    }

    // current character is a space
    // and the last word is not empty
    if (s[i] == ' ' && last_word.length() != 0)
      break;

    i--;
  }

  return last_word.length();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string s;
    getline(cin, s);

    int result = length_of_last_word(s);
    cout << result << '\n';
  }

  return 0;
}
