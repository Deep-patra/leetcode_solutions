#include <bits/stdc++.h>
using namespace std;

int find_max_form(vector<string> &strs, int m, int n) {
  int len = strs.size(), res = 0;

  // Preprocess the strs array
  vector<pair<int, int>> pre(len, make_pair(0, 0));
  for (int i = 0; i < len; i++) {
    string s = strs[i];

    for (char c : s) {
      if (c == '0')
        pre[i].first++;
      else
        pre[i].second++;
    }
  }

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < len; i++) {

    pair<int, int> curr = pre[i];

    if (curr.first > m || curr.second > n)
      continue;

    for (int r = m - curr.first; r >= 0; r--) {
      for (int c = n - curr.second; c >= 0; c--) {

        if (dp[r][c] > 0)
          dp[r + curr.first][c + curr.second] =
              max(dp[r + curr.first][c + curr.second], dp[r][c] + 1);
      }
    }

    dp[curr.first][curr.second] = max(dp[curr.first][curr.second], 1);
  }

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      res = max(res, dp[i][j]);
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len, m, n;
    cin >> len >> m >> n;

    vector<string> strs(len);
    for (int i = 0; i < len; i++)
      cin >> strs[i];

    int res = find_max_form(strs, m, n);
    cout << res << '\n';
  }

  return 0;
}
