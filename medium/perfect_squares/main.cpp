#include <bits/stdc++.h>
using namespace std;

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  return 'c';
}();

static int dp[10001];
static bool is_initialized = false;

// INFO: 2ms Runtime
int num_squares(int n) {

  if (is_initialized) {
    return dp[n];
  }

  is_initialized = 1;

  memset(dp, 0, sizeof(dp));

  for (int i = 1; i * i < 10001; i++)
    dp[i * i] = 1;

  for (int i = 1; i * i < 10001; i++) 
    for (int j = i * i; j < 10001; j ++) 
      dp[j] = min(dp[j] == 0 ? INT_MAX : dp[j], dp[j - i * i] + 1);

  return dp[n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    int result = num_squares(n);
    cout << result << '\n';
  }

  return 0;
}
