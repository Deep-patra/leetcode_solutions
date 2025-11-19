#include <bits/stdc++.h>
using namespace std;

int longest_subsequence(string s, int k) {
  int n = s.length(), res = 0;

  vector<int> zcnt(n + 1, 0);

  reverse(s.begin(), s.end());

  for (int i = n - 1; i >= 0; i--) {
    zcnt[i] += zcnt[i + 1];

    if (s[i] == '0')
      zcnt[i]++;
  }

  if (k == 0)
    return zcnt[0] + (s[0] == '0');

  int i = 0, j = 0;
  long long temp = s[i] == '1' ? 1 : 0;
  while (i >= j && i < n) {

    if (temp > k || (i - j + 1) >= 32) {
      j++;
      temp >>= 1;
      continue;
    }

    res = max(res, (i - j + 1) + zcnt[i + 1]);

    i++;

    if (i < n && s[i] == '1')
      temp |= (1LL << (i - j + 1));
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    int k;

    cin >> s >> k;

    int res = longest_subsequence(s, k);
    cout << res << '\n';
  }

  return 0;
}
