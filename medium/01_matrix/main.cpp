#include <bits/stdc++.h>
using namespace std;

const int row[4] = {-1, 1, 0, 0};
const int col[4] = {0, 0, 1, -1};


vector<vector<int>> update_matrix(vector<vector<int>> &matrix) {
  int m = matrix.size(), n = matrix[0].size();

  vector<vector<int>> result(m, vector<int>(n, -1));


  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];

    vector<vector<int>> result = update_matrix(matrix);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        cout << result[i][j] << " ";
      cout << '\n';
    }

    cout << '\n';
  }

  return 0;
}
