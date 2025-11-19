#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

static int dp[26][100001];
static bool initialize = 0;

void precompute() {
  for (int i = 0; i < 100001; i++) {
    for (int j = 0; j < 26; j++) {
      dp[j][i] = 1;

      if ((j + i) >= 26) {
        int diff = (j + i) - 26;

        dp[j][i] = dp[0][diff] + dp[1][diff];

        dp[j][i] %= MOD;
      }
    }
  }
}

int length_after_transformations(string s, int t) {
  int res = 0, l = s.length();

  if (!initialize) {
    initialize = 1;
    precompute();
  }

  int i = 0;
  while (i < l) {
    res += dp[s[i] - 'a'][t];
    res %= MOD;

    i++;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    int t;

    cin >> s >> t;

    int res = length_after_transformations(s, t);
    cout << res << '\n';
  }

  return 0;
}
