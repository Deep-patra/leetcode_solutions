#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*
curr => current number
pos => current position in the array
prev => previous value if present, or else -1
memo => memoize the count of ideal array forming with the current number at the
current position
**/
int count_ideal_arrays(int n, int max_value, int curr, int pos,
                       vector<vector<int>> &memo) {

  if (pos == n - 1)
    return 1;

  if (memo[curr][pos] != -1)
    return memo[curr][pos];

  int result = 0, multiple = 2;
  for (int i = curr; i <= max_value; i = (curr * (multiple++))) {
    result += (count_ideal_arrays(n, max_value, i, pos + 1, memo) % MOD);
    result %= MOD;
  }

  return memo[curr][pos] = result;
}

// TODO: Getting A TLE on large inputs, use Combinatorics to solve this problem
int ideal_arrays(int n, int maxValue) {
  vector<vector<int>> memo(maxValue + 1, vector<int>(n, -1));

  int result = 0;
  for (int i = 1; i <= maxValue; i++) {
    result += (count_ideal_arrays(n, maxValue, i, 0, memo) % MOD);
    result %= MOD;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, max_value;
    cin >> n >> max_value;

    int result = ideal_arrays(n, max_value);
    cout << result << '\n';
  }

  return 0;
}
