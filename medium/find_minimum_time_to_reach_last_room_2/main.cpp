#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> state;

// Using djikstra algorithm
int min_time_touch(vector<vector<int>> &moveTime) {
  int n = moveTime.size(), m = moveTime[0].size();
  vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

  dp[0][0] = 0;

  // visited matrix
  vector<vector<int>> v(n, vector<int>(m, 0));

  // 0, 1: coordinates, 2 : distance
  state t;

  auto cmp = [](const state &s1, const state &s2) {
    return get<2>(s1) > get<2>(s2);
  };

  priority_queue<state, vector<state>, decltype(cmp)> pq(cmp);

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  pq.push({0, 0, 0});

  while (!pq.empty()) {

    state s = pq.top();
    pq.pop();

    int x, y, dist;
    tie(x, y, dist) = s;

    // if already visited, continue
    if (v[x][y])
      continue;

    if (x == n - 1 && y == m - 1)
      break;

    v[x][y] = 1;

    for (int i = 0; i < 4; i++) {
      int nx = x + dirs[i][0], ny = y + dirs[i][1];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;

      int dist = max(dp[x][y], moveTime[nx][ny]) + (x + y) % 2 + 1;

      if (dp[nx][ny] > dist) {
        dp[nx][ny] = dist;
        pq.push({nx, ny, dist});
      }
    }
  }

  return dp[n - 1][m - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> move_time(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> move_time[i][j];

    int res = min_time_touch(move_time);
    cout << res << '\n';
  }

  return 0;
}
