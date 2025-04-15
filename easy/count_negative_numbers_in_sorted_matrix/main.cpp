#include <iostream>
#include <vector>
using namespace std;

int count_negatives(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  int result = 0;

  int low = 0, high = n - 1;
  for (int i = m - 1; i >= 0; i--) {
    int mid;

    while (low <= high) {

      mid = low + (high - low) / 2;

      if (grid[i][mid] < 0)
        high = mid - 1;

      else if (grid[i][mid] >= 0)
        low = mid + 1;
    }

    // cout << "Low => " << low << endl;

    result += n - low;

    low = mid;
    high = n - 1;
  }

  return result;
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

    int result = count_negatives(grid);
    cout << result << '\n';
  }

  return 0;
}
