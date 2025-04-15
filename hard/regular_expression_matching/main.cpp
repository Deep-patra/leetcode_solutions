#include <bits/stdc++.h>
using namespace std;

bool is_match(string s, string p) {

  int i = 0, j = 0;

  while (i < s.length() && j < p.length()) {
    if (p[j] != '.' && p[j] != '*') {

      if (j < p.length() - 1 && p[j + 1] == '*') {
        j++;
        continue;
      }

      if (s[i] != p[j])
        return false;

      i++;
      j++;
    }

    else if (p[j] == '.') {
      i++;
      j++;
    }

    else if (p[j] == '*') {

      if (p[j - 1] == '.') {
        if (j == s.length() - 1) return true;
      }

      else if (p[j - 1] != s[i])
        j++;

      else if (p[j - 1] == s[i])
        i++;
    }
  }

  if (j != p.length() && p[j] == '*')
    j++;

  if (j != p.length() || i != s.length())
    return false;

  return true;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s, p;
    cin >> s >> p;

    cout << "s => " << s << " p => " << p << endl;

    bool result = is_match(s, p);
    cout << result << '\n';
  }

  return 0;
}
