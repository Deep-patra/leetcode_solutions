#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

// TODO: Complete the implementation
int strange_printer(string s) {
  int l = s.length();
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < l; i++)
    dp[i][i] = 1;

  for (int i = 2; i <= l; i++) {
    for (int j = 0; j <= l - i; j++) {
      for (int k = j + 1; k < i + j; k++) {
      }
    }
  }

  return dp[0][l - 1];
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
