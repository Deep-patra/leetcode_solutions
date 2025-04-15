#include <iostream>
#include <vector>
using namespace std;

int min_cost_tabulation(vector<vector<int>> &grid) {

  int m = grid.size(), n = grid[0].size();

  vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

  dp[0][0] = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {

      if (i == 0 && j == 0)
        continue;

      if (i > 0)
        dp[i][j] = min(dp[i][j],
                       grid[i - 1][j] != 3 ? 1 + dp[i - 1][j] : dp[i - 1][j]);

      if (j > 0)
        dp[i][j] = min(dp[i][j],
                       grid[i][j - 1] != 1 ? 1 + dp[i][j - 1] : dp[i][j - 1]);

      if (i > 0 && j > 0) {
        dp[i][j] = min(dp[i][j],
                       grid[i - 1][j] != 3 ? 1 + dp[i - 1][j] : dp[i - 1][j]);
        dp[i][j] = min(dp[i][j],
                       grid[i][j - 1] != 1 ? 1 + dp[i][j - 1] : dp[i][j - 1]);
      }
    }

    // for (int j = n - 1; j >= 0 && i != 0; j--) {
    //   if (j == n - 1) {
    //     dp[i][j] = min(dp[i][j],
    //                    grid[i - 1][j] != 3 ? 1 + dp[i - 1][j] : dp[i - 1][j]);
    //     continue;
    //   }
    //
    //   dp[i][j] =
    //       min(dp[i][j], grid[i - 1][j] != 3 ? 1 + dp[i - 1][j] : dp[i - 1][j]);
    //   dp[i][j] =
    //       min(dp[i][j], grid[i][j + 1] != 2 ? 1 + dp[i][j + 1] : dp[i][j + 1]);
    // }
  }

  return dp[m - 1][n - 1];
}

int min_cost_recurse(vector<vector<int>> &grid, vector<vector<bool>> &visited,
                     vector<vector<int>> &memo, int row = 0, int col = 0) {

  int cost = INT_MAX;

  if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
    return cost - 1;

  if (memo[row][col] != -1)
    return memo[row][col];

  if (visited[row][col])
    return cost - 1;

  if (row == grid.size() - 1 && col == grid[0].size() - 1)
    return 0;

  visited[row][col] = 1;

  // taking the intialized path
  if (grid[row][col] == 1) {
    cost = min(cost, min_cost_recurse(grid, visited, memo, row, col + 1));

    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row + 1, col));
    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row - 1, col));
    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row, col - 1));
  } else if (grid[row][col] == 2) {
    cost = min(cost, min_cost_recurse(grid, visited, memo, row, col - 1));

    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row + 1, col));
    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row - 1, col));
    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row, col + 1));
  } else if (grid[row][col] == 3) {
    cost = min(cost, min_cost_recurse(grid, visited, memo, row + 1, col));

    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row, col - 1));
    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row - 1, col));
    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row, col + 1));
  } else {
    cost = min(cost, min_cost_recurse(grid, visited, memo, row - 1, col));

    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row, col - 1));
    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row + 1, col));
    cost = min(cost, 1 + min_cost_recurse(grid, visited, memo, row, col + 1));
  }

  return memo[row][col] = cost;
}

int min_cost(vector<vector<int>> &grid) {
  // vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
  // vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
  //
  // int cost = min_cost_recurse(grid, visited, memo, 0, 0);
  int cost = min_cost_tabulation(grid);

  return cost;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    int cost = min_cost(grid);
    cout << cost << '\n';
  }

  return 0;
}
