#include <bits/stdc++.h>
using namespace std;

int count_squares(vector<vector<int>> &matrix) {
  int n = matrix.size(), m = matrix[0].size(), res = 0;

  vector<int> prev(m, 0), curr(m, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      if (matrix[i][j]) {

        if (j == 0) {
          curr[j] = 1;

          res += curr[j];
          continue;
        }

        int v = min(curr[j - 1], min(prev[j - 1], prev[j]));
        curr[j] = v + 1;

        res += curr[j];
      }
    }

    prev = curr;
    curr = vector<int>(m, 0);
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

    vector<vector<int>> matrices(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> matrices[i][j];

    int res = count_squares(matrices);
    cout << res << '\n';
  }

  return 0;
}
