#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int possible_ways(int n, int x, int curr, vector<vector<int>> &memo) {

  int val = pow(curr, x);

  if (memo[n][curr] != -1)
    return memo[n][curr];

  if (n == 0 || val == n)
    return 1;

  if (val > n)
    return 0;

  int res = possible_ways(n - val, x, curr + 1, memo) +
            possible_ways(n, x, curr + 1, memo);
  return memo[n][curr] = res;
}

int number_of_ways(int n, int x) {

  vector<int> dp(n + 1, 0);

  int i = 1;
  while (pow(i, x) <= n) {

    int p = pow(i, x);
    for (int j = n - p; j >= 0; j --) {
      dp[j + p] += dp[j];
      dp[j + p] %= MOD;
    }

    dp[p] ++;
    dp[p] %= MOD;

    i ++;
  }


  return dp[n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, x;
    cin >> n >> x;

    int res = number_of_ways(n, x);
    cout << res << '\n';
  }

  return 0;
}
