#include <iostream>
#include <vector>
using namespace std;

string clear_digits(string s) {
  bool removed[100];

  memset(removed, 0, sizeof(removed));

  int pos = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      pos = i;

      while (pos > 0) {
        pos--;

        if ((s[pos] < '0' || s[pos] > '9') && !removed[pos]) {
          removed[pos] = 1;
          break;
        }
      }

      removed[i] = 1;
    }
  }

  string result = "";
  for (int i = 0; i < s.length(); i++) {
    if (!removed[i])
      result.push_back(s[i]);
  }

  return result;
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    string result = clear_digits(s);
    cout << result << '\n';
  }

  return 0;
}
