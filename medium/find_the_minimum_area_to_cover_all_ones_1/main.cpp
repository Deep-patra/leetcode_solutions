#include <bits/stdc++.h>
using namespace std;

int minimum_area(vector<vector<int>> &grid) {

  int n = grid.size(), m = grid[0].size();

  int top = n, bottom = 0, left = m, right = 0;

  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {

      if (grid[i][j]) {
        top = min(top, i);
        bottom = max(bottom, i);

        left = min(left, j);
        right = max(right, j);
      }

    }
  }

  return (bottom - top + 1) * (right - left + 1);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++)
        cin >> grid[i][j];

    int res = minimum_area(grid);
    cout << res << '\n';
  }

  return 0;
}
