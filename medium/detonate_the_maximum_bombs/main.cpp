#include <bits/stdc++.h>
using namespace std;

int maximum_bombs(vector<vector<int>> &bombs) {

  int n = bombs.size(), res = 0;

  for (int k = 0; k < n; k++) {

    vector<bool> visited(n, 0);

    queue<pair<int, int>> q;
    q.push({k, 1});

    visited[k] = 1;

    while (!q.empty()) {

      pair<int, int> f = q.front();
      q.pop();

      vector<int> bomb = bombs[f.first], triggered_bombs;

      int d = bomb[2] * bomb[2];
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {

          vector<int> curr = bombs[i];
          int y = (curr[1] - bomb[1]), x = (curr[0] - bomb[0]);

          if ((y * y) + (x * x) <= d) {
            visited[i] = 1;
            triggered_bombs.push_back(i);
          }
        }
      }

      for (int b : triggered_bombs)
        q.push({b, f.second + (int)triggered_bombs.size()});

      res = max(res, f.second + (int)triggered_bombs.size());
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> bombs(n, vector<int>(3));
    for (int i = 0; i < n; i++)
      cin >> bombs[i][0] >> bombs[i][1] >> bombs[i][2];

    int res = maximum_bombs(bombs);
    cout << res << endl;
  }

  return 0;
}
