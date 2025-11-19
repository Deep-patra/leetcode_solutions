#include <bits/stdc++.h>
using namespace std;

string last_substring(string s) {

  int len = s.length();

  int i = 0, j = 1;

  while (j < len) {
    int k = 0;

    while (j + k < len && s[i + k] == s[j + k])
      k++;

    if (j + k < len && s[i + k] < s[j + k]) {
      int t = i;
      i = j;
      j = max(j + 1, t + k + 1);
    }

    else
      j = j + k + 1;
  }

  return s.substr(i, len - i);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    string res = last_substring(s);
    cout << res << '\n';
  }

  return 0;
}
