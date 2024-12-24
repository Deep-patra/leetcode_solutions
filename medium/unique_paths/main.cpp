#include <iostream>
#include <vector>
using namespace std;

int unique_paths_with_obstacle(vector<vector<int>> &obstacleGrid) {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int row, col;
    cin >> row >> col;

    vector<vector<int>> grid(row, vector(col, 0));
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        cin >> grid[i][j];

    int result = unique_paths_with_obstacle(grid);

    cout << result << '\n';
  }

  return 0;
}
