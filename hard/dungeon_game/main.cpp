#include <bits/stdc++.h>
using namespace std;

int calculate_minimum_hp(vector<vector<int>> &dungeon) {
  int n = dungeon.size(), m = dungeon[0].size();

  typedef vector<vector<pair<int, int>>> vpii;

  // first -> current health, second -> starting health
  vpii dp(n, vector<pair<int, int>>(m, {INT_MAX, INT_MAX}));

  dp[0][0] = dungeon[0][0] <= 0 ? make_pair(1, dungeon[0][0] + 1)
                                : make_pair(dungeon[0][0], 0);

  for (int i = 1; i < n; i++) {
    int h = dp[i - 1][0].first + dungeon[i][0];
    dp[i][0] = h <= 0 ? make_pair(1, dp[i - 1][0].second + abs(h) + 1)
                      : make_pair(h, dp[i - 1][0].second);
  }

  for (int i = 1; i < m; i++) {
    int h = dp[0][i - 1].first + dungeon[0][i];
    dp[0][i] = h <= 0 ? make_pair(1, dp[0][i - 1].second + abs(h) + 1)
                      : make_pair(h, dp[0][i - 1].second);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {

      // from left
      int h = dp[i][j - 1].first + dungeon[i][j];
      int l_curr = max(1, h);
      int l_start =
          h <= 0 ? dp[i][j - 1].second + abs(h) + 1 : dp[i][j - 1].second;

      // from top
      h = dp[i - 1][j].first + dungeon[i][j];
      int r_curr = max(1, h);
      int r_start =
          h <= 0 ? dp[i - 1][j].second + abs(h) + 1 : dp[i - 1][j].second;

      if (l_start <= r_start) {
        if (l_start == r_start)
          dp[i][j] = l_curr < r_curr ? make_pair(r_curr, r_start)
                                     : make_pair(l_curr, l_start);

        else
          dp[i][j] = make_pair(l_curr, l_start);

      } else
        dp[i][j] = make_pair(r_curr, r_start);
    }
  }

  return dp[n - 1][m - 1].second;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> dungeon(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> dungeon[i][j];
      }
    }

    int result = calculate_minimum_hp(dungeon);
    cout << result << '\n';
  }

  return 0;
}
