#include <iostream>
#include <vector>
using namespace std;

bool search_matrix(vector<vector<int>> &matrix, int target) {
  int m = matrix.size(), n = matrix[0].size();

  int low = 0, high = m - 1, mid;

  // find the correct row
  while (low <= high) {
    mid = low + (high - low) / 2;

    if (target >= matrix[mid][0] && target <= matrix[mid][n - 1])
      break;

    else if (target < matrix[mid][0])
      high = mid - 1;

    else
      low = mid + 1;
  }

  int curr_row = mid;

  low = 0;
  high = n - 1;

  // find the correct column
  while (low <= high) {
    mid = low + (high - low) / 2;

    if (matrix[curr_row][mid] == target)
      return 1;

    else if (matrix[curr_row][mid] < target)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return 0;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m, target;
    cin >> target >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];

    bool result = search_matrix(matrix, target);
    cout << result << '\n';
  }

  return 0;
}
