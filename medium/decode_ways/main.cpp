#include <iostream>
#include <vector>
using namespace std;

static int dp[101];

int num_decodings(string s) {
  int n = s.length();

  memset(dp, 0, sizeof(dp));

  if (s[0] == '0')
    return 0;

  if (n == 1)
    return 1;

  dp[0] = 1;

  for (int i = 1; i < n; i++) {
    if (s[i - 1] == '0' && s[i] == '0' || s[i] == '0' && s[i - 1] > '2') return 0;

    if (s[i] == '0')
      dp[i] = i == 1 ? 1 : dp[i - 2];

    else {

      if ((s[i] > '6' && s[i - 1] == '2') || s[i - 1] > '2' || s[i - 1] == '0')
        dp[i] = dp[i - 1];

      else
        dp[i] = i == 1 ? dp[i - 1] + 1 : dp[i - 1] + dp[i - 2];
    }
  }

  for (int val : dp)
    cout << val << " ";

  cout << '\n';

  return dp[n - 1];
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int result = num_decodings(s);
    cout << result << '\n';
  }

  return 0;
}
