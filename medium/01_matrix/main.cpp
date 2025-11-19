#include <bits/stdc++.h>
using namespace std;

int rows[4] = {0, 0, 1, -1}, cols[4] = {-1, 1, 0, 0};

void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited,
         vector<vector<int>> &comp, int i, int j) {

  int m = matrix.size(), n = matrix[0].size(), res = INT_MAX;

  visited[i][j] = 1;

  for (int d = 0; d < 4; d++) {
    int r = i + rows[d], c = j + cols[d];

    if (r >= 0 && r < m && c >= 0 && c < n) {

      if (visited[r][c])
        continue;

      if (matrix[r][c] == 1 && comp[r][c] == 0)
        dfs(matrix, visited, comp, r, c);

      else if (matrix[r][c] == 0)
        res = min(res, 1);

      if (matrix[r][c] == 1 && comp[r][c] != 0)
        res = min(res, 1 + comp[r][c]);
    }
  }

  comp[i][j] = res;
}

vector<vector<int>> update_matrix(vector<vector<int>> &matrix) {

  int m = matrix.size(), n = matrix[0].size();

  vector<vector<int>> comp(m, vector<int>(n, 0));
  vector<vector<bool>> visited(m, vector<bool>(n, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] && comp[i][j] == 0)
        dfs(matrix, visited, comp, i, j);
    }
  }

  return comp;
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
