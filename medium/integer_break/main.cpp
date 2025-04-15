#include <bits/stdc++.h>
using namespace std;

static int dp[59];
static bool is_initialized = 0;

int integer_break(int n) {

  if (is_initialized) return dp[n];

  is_initialized = 1;

  dp[1] = 1;
  dp[2] = 1;

  for (int i = 3; i < 59; i++) 
    for (int j = 1; j < i; j++) 
      dp[i] = max({ dp[i], (i - j) * j, dp[i - j] * dp[j], dp[i - j] * j, (i - j) * dp[j] });

  return dp[n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    int result = integer_break(n);
    cout << result << '\n';
  }

  return 0;
}
