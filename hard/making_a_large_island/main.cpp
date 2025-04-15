#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// INFO: RUNTIME 184 ms Beats 50%
int largest_island(vector<vector<int>> &grid) {
  int n = grid.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));

  vector<int> group(n, 0);

  int curr_group = 0;
  int curr_group_size = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (!grid[i][j] || dp[i][j] != -1)
        continue;

      queue<pair<int, int>> q;
      q.push({i, j});

      curr_group_size = 0;

      while (!q.empty()) {
        pair<int, int> front = q.front();
        int row = front.first, col = front.second;

        q.pop();

        if (dp[row][col] != -1)
          continue;

        dp[row][col] = curr_group;

        curr_group_size++;

        if (row > 0 && grid[row - 1][col])
          q.push({row - 1, col});

        if (row < n - 1 && grid[row + 1][col])
          q.push({row + 1, col});

        if (col > 0 && grid[row][col - 1])
          q.push({row, col - 1});

        if (col < n - 1 && grid[row][col + 1])
          q.push({row, col + 1});
      }

      if (curr_group >= group.size())
        group.resize(curr_group + 1);

      group[curr_group++] = curr_group_size;
    }
  }

  int result = 0;

  // find the best position to apply operations
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (grid[i][j])
        continue;

      int res = 0;
      set<int> s;

      if (i > 0 && grid[i - 1][j]) {
        s.insert(dp[i - 1][j]);
        res += group[dp[i - 1][j]];
      }

      if (i < n - 1 && grid[i + 1][j] && s.find(dp[i + 1][j]) == s.end()) {
        s.insert(dp[i + 1][j]);
        res += group[dp[i + 1][j]];
      }

      if (j > 0 && grid[i][j - 1] && s.find(dp[i][j - 1]) == s.end()) {
        s.insert(dp[i][j - 1]);
        res += group[dp[i][j - 1]];
      }

      if (j < n - 1 && grid[i][j + 1] && s.find(dp[i][j + 1]) == s.end()) {
        s.insert(dp[i][j + 1]);
        res += group[dp[i][j + 1]];
      }

      if (res > 0)
        res += 1;

      result = max(result, res);
    }
  }

  if (!result)
    for (int i = 0; i < group.size(); i++)
      result = max(result, group[i]);

  return max(result, 1);
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

    int result = largest_island(grid);
    cout << result << '\n';
  }

  return 0;
}
