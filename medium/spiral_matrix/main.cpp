#include <bits/stdc++.h>
using namespace std;

vector<int> spiral_order(vector<vector<int>> &matrix) {
  vector<int> result;

  int r = matrix.size(), c = matrix[0].size();

  int cnt = 0;
  while (true) {
    // left to right
    for (int i = cnt; i < (c - i); i ++) 
       result.push_back(matrix[cnt][i]);

    // up to down
    for (int i = cnt + 1; i < (r - cnt); i ++)
      result.push_back(matrix[i][c - cnt - 1]);

    // right to left
    for (int i = (c - (i + 1)); i >= cnt; i --)
      result.push_back(matrix[r - cnt - 1][i]);

    // down to up
    for (int i = (r - cnt - 2); i >= (cnt + 1); i --)
      result.push_back(matrix[i][cnt]);

    cnt ++;
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
