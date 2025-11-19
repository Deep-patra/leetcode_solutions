#include <bits/stdc++.h>
using namespace std;

int max_operations(string s) {

  int n = s.length(), cnt = 0, ops = 0;

  char prev = '0';
  for (int i = 0; i < n; i++) {

    if (s[i] == '1') {
      if (prev == '0') {
        ops += cnt;
      }

      cnt++;
    }

    prev = s[i];
  }

  if (s[n - 1] == '0')
    ops += cnt;

  return ops;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int res = max_operations(s);
    cout << res << endl;
  }

  return 0;
}
