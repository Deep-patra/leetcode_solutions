#include <bits/stdc++.h>  
using namespace std;

string smallest_string(string s) {
  int l = s.length();

  int i = 0, j = 0;
  while (j < l && i <= j) {

    if (i == j && s[i] == 'a') {
      i ++;
      j ++;
      continue;
    }

    s[j++] --;

    if (j < l && s[j] == 'a')
      break;
  }

  if (i == j) {
    s[l - 1] = 'z';
  }

  return s;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    string res = smallest_string(s);
    cout << res << endl;
  }

  return 0;
}
