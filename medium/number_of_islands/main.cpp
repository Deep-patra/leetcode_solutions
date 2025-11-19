#include <bits/stdc++.h>
using namespace std;

int x_dir[4] = {-1, 1, 0, 0}, y_dir[4] = {0, 0, 1, -1};

void fill(vector<vector<char>> &grids, int i, int j) {

  if (grids[i][j] == '_')
    return;

  if (grids[i][j] == '1')
    grids[i][j] = '_';

  int n = grids.size(), m = grids[0].size();

  for (int d = 0; d < 4; d++) {
    int r = i + x_dir[d], c = j + y_dir[d];

    if (r >= 0 && r < n && c >= 0 && c < m) {
      if (grids[r][c] == '1')
        fill(grids, r, c);
    }
  }
}

int num_islands(vector<vector<char>> &grids) {

  int n = grids.size(), m = grids[0].size(), res = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grids[i][j] == '1') {

        for (vector<char> l : grids) {
          for (char c : l)
            cout << c << " ";

          cout << endl;
        }

        fill(grids, i, j);

        res++;
      }
    }
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

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    int res = num_islands(grid);
    cout << res << '\n';
  }

  return 0;
}
