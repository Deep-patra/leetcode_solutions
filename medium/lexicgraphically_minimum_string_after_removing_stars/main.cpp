#include <bits/stdc++.h>
using namespace std;

// INFO: Wrong Answer (HINT: Use Greedy Stack approach)
string clear_strings(string s) {
  int freq[26], n = s.length();
  memset(freq, 0, sizeof(freq));

  char min_char = 'z';

  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {

      for (int j = 0; j < 26; j++) {
        if (freq[j] > 0) {
          freq[j]--;

          break;
        }
      }

    } else 
      freq[s[i] - 'a']++;

  }

  string res;

  for (char c : s) {
    if (c != '*' && freq[c - 'a'] > 0) {
      res.push_back(c);
      freq[c - 'a']--;
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    string res = clear_strings(s);
    cout << res << '\n';
  }

  return 0;
}
