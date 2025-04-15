#include <iostream>
using namespace std;

int longest_substring(string s) {
  
  int ch[256];
  memset(ch, -1, sizeof(ch));

  int l = 0, r = 0, max_len = 1;

  while (r < s.length()) {

    int c = s[r] - 'a';

    if (ch[c] != -1) {
      int end = ch[c] + 1;

      while (l < end) {
        ch[s[l]] = -1;
        l ++;
      }
    }

    max_len = max(max_len, (r + 1) - l);
    
    ch[c] = r;
    r ++;
  }

  return max_len;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int result = longest_substring(s);
    cout << result << '\n';
  }

  return 0;
}
