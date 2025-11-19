#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

bool recurse_sol(string &s1, string &s2, string &s3, int i, int j, int k) {

  if (i > s3.length() || j > s1.length() || k > s2.length())
    return 0;

  if (i == s3.length() && j == s1.length() && k == s2.length())
    return dp[i][j] = 1;

  if (dp[i][j] != -1)
    return dp[i][j];

  bool res = 0;

  if (s3[i] == s1[j])
    res |= recurse_sol(s1, s2, s3, i + 1, j + 1, k);

  if (s3[i] == s2[k])
    res |= recurse_sol(s1, s2, s3, i + 1, j, k + 1);

  return dp[i][j] = res;
}

// Now turn this recursive approach to Tabulation approach
bool is_inter_leave_memoization(string s1, string s2, string s3) {
  memset(dp, -1, sizeof(dp));
  return recurse_sol(s1, s2, s3, 0, 0, 0);
}

bool is_inter_leave(string s1, string s2, string s3) {
  memset(dp, 0, sizeof(dp));

  int m = s1.length(), n = s2.length();

  if (m + n != s3.length())
    return 0;

  dp[0][0] = 1;

  // when s1 is empty
  for (int i = 1; i <= n; i++)
    dp[0][i] = (s2[i - 1] == s3[i - 1]) && dp[0][i - 1];

  // when s2 is empty
  for (int i = 1; i <= m; i++)
    dp[i][0] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][0];

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] = ((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]) ||
                 ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1]);

  return dp[m][n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    // bool result = is_inter_leave_memoization(s1, s2, s3);
    bool result = is_inter_leave(s1, s2, s3);
    cout << result << '\n';
  }

  return 0;
}
