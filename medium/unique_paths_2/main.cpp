#include <iostream>
#include <vector>
using namespace std;

int unique_paths_with_obstacles(vector<vector<int>> &obstacleGrid) {

  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  vector<vector<int>> ways(m, vector<int>(n, 0));

  if (obstacleGrid[0][0])
    return 0;

  ways[0][0] = 1;

  for (int i = 1; i < n; i++) {
    if (obstacleGrid[0][i]) {
      ways[0][i] = 0;
      break;
    }

    ways[0][i] = 1;
  }

  for (int i = 1; i < m; i++) {
    if (obstacleGrid[i][0]) {
      ways[i][0] = 0;
      break;
    }

    ways[i][0] = 1;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (obstacleGrid[i][j]) {
        ways[i][j] = 0;
        continue;
      }

      ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
    }
  }

  return ways[m - 1][n - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> obstacleGrid[i][j];

    int result = unique_paths_with_obstacles(obstacleGrid);
    cout << result << '\n';
  }

  return 0;
}
