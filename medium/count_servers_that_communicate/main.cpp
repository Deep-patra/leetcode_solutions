#include <iostream>
#include <vector>
using namespace std;

int count_servers(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  vector<int> row_counts(m, 0), col_counts(n, 0);

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j]) {
        row_counts[i]++;
        col_counts[j]++;
      }
  int server_communicate = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j])
        server_communicate += row_counts[i] > 1 || col_counts[j] > 1;
    }
  }

  return server_communicate;
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

    int result = count_servers(grid);
    cout << result << '\n';
  }

  return 0;
}
