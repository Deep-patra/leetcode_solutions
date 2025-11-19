#include <bits/stdc++.h>
using namespace std;

int row[4] = {-1, 1, 0, 0}, col[4] = {0, 0, -1, 1};

int swim_in_water(vector<vector<int>> &grid) {
  int n = grid.size();

  typedef tuple<int, int, int> tii;

  vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

  auto comparator = [](tii &a, tii &b) -> bool {
    return get<0>(a) > get<0>(b);
  };

  priority_queue<tii, vector<tii>, decltype(comparator)> pq(comparator);

  pq.push({grid[0][0], 0, 0});

  while (!pq.empty()) {

    auto [t, x, y] = pq.top();
    pq.pop();

    dp[x][y] = min(dp[x][y], t);

    if (x == n - 1 && y == n - 1)
      break;

    for (int k = 0; k < 4; k++) {
      int r = x + row[k], c = y + col[k];

      if (r < 0 || c < 0 || r >= n || c >= n)
        continue;

      int time = t + max(0, grid[r][c] - t);

      if (dp[r][c] > time)
        pq.push({time, r, c});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << dp[i][j] << " ";

    cout << endl;
  }

  return dp[n - 1][n - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    int res = swim_in_water(grid);
    cout << res << endl;
  }

  return 0;
}
