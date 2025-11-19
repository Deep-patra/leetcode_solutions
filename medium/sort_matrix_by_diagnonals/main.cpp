#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sort_matrix(vector<vector<int>> &grid) {
  int n = grid.size();

  priority_queue<int, vector<int>, greater<int>> pq1;
  priority_queue<int> pq2;

  // sort the top-right triangle
  for (int i = 1; i < n - 1; i++) {

    for (int r = 0, c = i; r < n && c < n; r++, c++)
      pq1.push(grid[r][c]);

    for (int r = 0, c = i; r < n && c < n; r++, c++) {
      grid[r][c] = pq1.top();
      pq1.pop();
    }
  }

  // sort the bottom-left triangle
  for (int i = 0; i < n - 1; i++) {

    for (int r = i, c = 0; r < n && c < n; r++, c++)
      pq2.push(grid[r][c]);

    for (int r = i, c = 0; r < n && c < n; r++, c++) {
      grid[r][c] = pq2.top();
      pq2.pop();
    }
  }

  return grid;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    vector<vector<int>> res = sort_matrix(grid);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << grid[i][j] << " ";

      cout << endl;
    }
  }

  return 0;
}
