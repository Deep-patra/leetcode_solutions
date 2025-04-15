#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int find_max_fish(vector<vector<int>> &grid) {

  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> visited(m, vector<int>(n, -1));

  int max_fishes = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0 || visited[i][j] != -1)
        continue;

      // Breadth first search Approach
      queue<pair<int, int>> q;

      q.push({i, j});

      int curr_val = 0;
      while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        // row and column
        int r = front.first, c = front.second;

        if (visited[r][c] != -1)
          continue;

        curr_val += grid[r][c];
        visited[r][c] = curr_val;

        // check the top cell
        if (r > 0 && visited[r - 1][c] == -1 && grid[r - 1][c] > 0)
          q.push({r - 1, c});

        // check the bottom cell
        if (r < m - 1 && visited[r + 1][c] == -1 && grid[r + 1][c] > 0)
          q.push({r + 1, c});

        // check the left cell
        if (c > 0 && visited[r][c - 1] == -1 && grid[r][c - 1] > 0)
          q.push({r, c - 1});

        // check the right cell
        if (c < n - 1 && visited[r][c + 1] == -1 && grid[r][c + 1] > 0)
          q.push({r, c + 1});
      }

      max_fishes = max(max_fishes, curr_val);
    }
  }

  return max_fishes;
}

int main() {
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

    int result = find_max_fish(grid);
    cout << result << '\n';
  }

  return 0;
}
