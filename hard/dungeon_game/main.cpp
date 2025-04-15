#include <iostream>
#include <vector>
using namespace std;

// TODO: Cannot pass one testcase
int calculate_minimum_hp(vector<vector<int>> &dungeon) {
  int n = dungeon.size(), m = dungeon[0].size();

  // starting hp and current hp
  vector<vector<pair<int, int>>> dp(
      n, vector<pair<int, int>>(m, {INT_MAX, INT_MAX}));

  dp[0][0] = dungeon[0][0] < 0 ? make_pair(abs(dungeon[0][0]) + 1, 1)
                               : make_pair(1, dungeon[0][0] + 1);

  for (int i = 1; i < m; i++)
    dp[0][i] = (dp[0][i - 1].second + dungeon[0][i]) < 0
                   ? make_pair(dp[0][i - 1].first +
                                   abs(dp[0][i - 1].second + dungeon[0][i]) + 1,
                               1)
                   : make_pair(dp[0][i - 1].first,
                               dp[0][i - 1].second + dungeon[0][i]);

  for (int i = 1; i < n; i++)
    dp[i][0] = (dp[i - 1][0].second + dungeon[i][0] < 0)
                   ? make_pair(dp[i - 1][0].first +
                                   abs(dp[i - 1][0].second + dungeon[i][0]) + 1,
                               1)
                   : make_pair(dp[i - 1][0].first,
                               dp[i - 1][0].second + dungeon[i][0]);

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {

      pair<int, int> from_left =
          dp[i][j - 1].second + dungeon[i][j] <= 0
              ? make_pair(dp[i][j - 1].first +
                              abs(dp[i][j - 1].second + dungeon[i][j]) + 1,
                          1)
              : make_pair(dp[i][j - 1].first,
                          dp[i][j - 1].second + dungeon[i][j]);

      pair<int, int> from_top =
          dp[i - 1][j].second + dungeon[i][j] <= 0
              ? make_pair(dp[i - 1][j].first +
                              abs(dp[i - 1][j].second + dungeon[i][j]) + 1,
                          1)
              : make_pair(dp[i - 1][j].first,
                          dp[i - 1][j].second + dungeon[i][j]);

      dp[i][j] = from_left.first < from_top.first ? from_left : from_top;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << '(' << dp[i][j].first << " ," << dp[i][j].second << ')' << " ";
    }

    cout << '\n';
  }

  return dp[n - 1][m - 1].first;
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
