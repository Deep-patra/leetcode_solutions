#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<char> &v) {

  int upper[26], lower[26];
  memset(upper, 0, sizeof(upper));
  memset(lower, 0, sizeof(lower));

  for (char c : v) {
    if (c >= 'A' && c <= 'Z') upper[c - 'A'] ++;
    else if (c >= 'a' && c <= 'z') lower[c - 'a'] ++;
  }

  int k = 0;
  for (int i = 0; i < 26; i ++) {
    if (upper[i] > 0) {
      while (upper[i] > 0) {
        v[k ++] = 'A' + i;
        upper[i] --;
      }
    } 
  }

  for (int i = 0; i < 26; i ++) {
    if (lower[i] > 0) {
      while (lower[i] > 0) {
        v[k ++] = 'a' + i;
        lower[i] --;
      }
    }
  }
}

string sort_vowels(string s) {

  auto is_vowel = [](char c) -> bool {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
  };

  vector<char> v;

  for (char c : s)
    if (is_vowel(c))
      v.push_back(c);

  counting_sort(v);

  for (int i = s.length() - 1; i >= 0; i--) {
    if (is_vowel(s[i])) {
      s[i] = v.back();
      v.pop_back();
    }
  }

  return s;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    string res = sort_vowels(s);
    cout << res << endl;
  }

  return 0;
}
