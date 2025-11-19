#include <bits/stdc++.h>
using namespace std;

int count_score(string &s, int val, const string &pat) {
  int len = s.length(), score = 0;

  for (int i = 0, prev = -1; i < len; i ++) {

    if (s[i] == '_') continue;

    if (prev != -1 && s[prev] == pat[0] && s[i] == pat[1]) {

      int l = prev, r = i;

      while (l >= 0 && r < len) {

        if (s[l] == pat[0] && s[r] == pat[1]) {
          score += val;

          s[l] = s[r] = '_';
        } else 
          break;

        while (l >= 0 && s[l] == '_')
          l --;

        while (r < len && s[r] == '_')
          r ++;
      }

    } 

    prev = i;

    cout << s << endl;
  }

  return score;
}

// TODO: Write a Efficient Implementation, It is Really slow
int maximum_gain(string s, int x, int y) {

  int l = s.length(), score = 0;

  score += count_score(s, max(x, y), x > y ? "ab" : "ba");
  score += count_score(s, min(x, y), x > y ? "ba" : "ab");

  return score;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;

    int res = maximum_gain(s, x, y);
    cout << res << '\n';
  }

  return 0;
}
