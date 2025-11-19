#include <bits/stdc++.h>  
using namespace std;

int num_sub(string s) {
  const int MOD = 1e9 + 7;

  int l = s.length(), res = 0, prev = 0;

  for (int i = 0; i < l; i ++) {
    if (s[i] == '1') {

      prev = prev + 1;

      res += prev;
      res %= MOD;
    } else 
      prev = 0;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    int res = num_sub(s);
    cout << res << endl;
  }

  return 0;
}
