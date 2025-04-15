#include <bits/stdc++.h>
using namespace std;

// TODO: Unsolved
// INFO: Approaches: Sorting and Median | Prefix and suffix array | Two pointer
// method
int min_operations(vector<vector<int>> &grid, int x) {
  int m = grid.size(), n = grid[0].size();
  int minimum = INT_MAX, maximum = INT_MIN;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      minimum = min(minimum, grid[i][j]);
      maximum = max(maximum, grid[i][j]);
    }
  }

  if (minimum == maximum)
    return 0;

  int ops = INT_MAX, num = minimum;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {

      if (grid[i][j] == maximum || grid[i][j] == minimum)
        continue;

      int curr_ops = abs(grid[i][j] - minimum) + abs(maximum - grid[i][j]);

      if (curr_ops % x != 0)
        return -1;

      curr_ops /= x;

      if (curr_ops < ops) {
        num = grid[i][j];
        ops = curr_ops;
      }
    }
  }

  // calculate the ops
  ops = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ops += abs(grid[i][j] - num) / x;
    }
  }

  return ops;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n, x;
    cin >> m >> n >> x;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    int result = min_operations(grid, x);
    cout << result << '\n';
  }

  return 0;
}
