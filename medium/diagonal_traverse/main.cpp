#include <bits/stdc++.h>
using namespace std;

vector<int> find_diagonal_order(vector<vector<int>> &mat) {

  int n = mat.size(), m = mat[0].size(), diag = 0;

  vector<int> res;

  for (int i = 0; i < m; i++) {

    int r = 0, c = i;

    if (diag & 1) {

      while (r < n && c >= 0)
        res.push_back(mat[r++][c--]);

    } else {

      r = min(n - 1, i);
      c = max(0, i - n - 1);

      while (r >= 0 && c <= i)
        res.push_back(mat[r--][c++]);
    }

    diag++;
  }

  for (int i = 1; i < n; i++) {

    int r = i, c = m - 1;

    if (diag & 1) {
      while (r < n && c >= 0)
        res.push_back(mat[r++][c--]);
    } else {

      r = min(n - 1, i - m - 1);
      c = max(0, m - 1 - i);

      while (r >= i && c < m)
        res.push_back(mat[r++][c++]);
    }

    diag++;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> mat[i][j];

    vector<int> res = find_diagonal_order(mat);

    for (int v : res)
      cout << v << " ";

    cout << endl;
  }

  return 0;
}
