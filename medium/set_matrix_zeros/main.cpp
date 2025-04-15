#include <bits/stdc++.h>
using namespace std;

bool zeroed_row[200], zeroed_col[200];

void set_zeros(vector<vector<int>> &matrix) {
  int m = matrix.size(), n = matrix[0].size();

  memset(zeroed_row, 0, sizeof(zeroed_row));
  memset(zeroed_col, 0, sizeof(zeroed_col));

  stack<pair<int, int>> s;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (matrix[i][j] == 0)
        s.push(make_pair(i, j));

  while (!s.empty()) {
    pair<int, int> top = s.top;
    s.pop();

    // zero the col
    if (!zeroed_col[top.second])
      for (int i = 0; i < m; i++)
        matrix[i][top.second] = 0;

    // zero the row
    if (!zeroed_row[top.first])
      for (int j = 0; j < n; j++)
        matrix[top.first][j] = 0;

    zeroed_row[top.first] = 1;
    zeroed_col[top.second] = 1;
  }
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int row, col;
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        cin >> matrix[i][j];

    set_zeros(matrix);

    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        cout << matrix[i][j] << " ";

    cout << '\n';
  }

  return 0;
}
