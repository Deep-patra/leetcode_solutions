#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int strange_printer(string s) {
  int n = s.length();
  memset(dp, 0, sizeof(dp));

  return dp[0][n - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int result = strange_printer(s);
    cout << result << '\n';
  }

  return 0;
}
