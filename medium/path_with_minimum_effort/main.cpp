#include <bits/stdc++.h>  
using namespace std;

int row[4] = {-1, 1, 0, 0}, col[4] = {0, 0, -1, 1};

int minimum_effort_path(vector<vector<int>> &heights) {
  int n = heights.size(), m = heights[0].size();

  vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

  typedef tuple<int, int, int> tii;

  auto cmp = [](tii &a, tii &b) {
    return get<0>(a) > get<0>(b);
  };

  priority_queue<tii, vector<tii>, decltype(cmp)> pq(cmp);

  pq.push({ 0, 0, 0 });

  while (!pq.empty()) {
    
    auto [ e, x, y ] = pq.top();
    pq.pop();

    dp[x][y] = min(dp[x][y], e);

    if (x == n - 1 && y == m - 1) break;

    for (int k = 0; k < 4; k ++) {
      int r = x + row[k], c = y + col[k];

      if (r < 0 || c < 0 || r >= n || c >= m) continue;

      int effort = max(e, abs(heights[r][c] - heights[x][y]));

      if (effort < dp[r][c])
        pq.push({ effort, r, c });
    }    
  }

  return dp[n - 1][m - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m, 0));
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++)
        cin >> heights[i][j];

    int res = minimum_effort_path(heights);
    cout << res << endl;
  }

  return 0;
}
