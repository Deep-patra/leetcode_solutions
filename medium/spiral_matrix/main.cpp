#include <bits/stdc++.h>
using namespace std;

void traverse_spirally(vector<vector<int>> &matrix, int i, int j,
                       vector<int> &result) {}

vector<int> spiral_order(vector<vector<int>> &matrix) {
  vector<int> result;
  traverse_spirally(matrix, 0, 0, result);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];

    vector<int> result = spiral_order(matrix);

    for (int val : result)
      cout << val << '\n';
  }

  return 0;
}
