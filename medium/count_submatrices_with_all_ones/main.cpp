#include <bits/stdc++.h>
using namespace std;

// TODO: Complete the Implementation
int max_submat(vector<vector<int>> &mat) {
  int n = mat.size(), m = mat[0].size();
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> matrix[i][j];

    int res = sub_mat(matrix);
    cout << res << '\n';
  }

  return 0;
}
