#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long dp[100001];
bool initialized = 0;

// make a different dp array for 7 and 9, bcoz they  correlate to 4 characters
int count_texts(string pressed_keys) {

  int n = pressed_keys.length();

  if (n == 0)
    return 0;

  if (!initialized) {

    memset(dp, 0, sizeof(dp));

    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < 100001; i++)
      dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;

    initialized = 1;
  }

  pressed_keys.push_back('$');

  char prev = pressed_keys[0];

  long long res = 1;

  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (prev != pressed_keys[i]) {
      res *= dp[cnt];
      res %= MOD;

      cnt = 1;
    } else
      cnt++;

    prev = pressed_keys[i];
  }

  pressed_keys.pop_back();

  return (int)(res % MOD);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string pressed_keys;
    cin >> pressed_keys;

    int res = count_texts(pressed_keys);
    cout << res << endl;
  }

  return 0;
}
