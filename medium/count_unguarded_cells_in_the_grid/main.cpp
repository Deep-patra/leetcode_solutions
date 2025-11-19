#include <bits/stdc++.h>  
using namespace std;

int count_unguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
  
  vector<vector<int>> grid(m, vector<int>(n, 0));

  for (vector<int> guard: guards) 
    grid[guard[0]][guard[1]] = 1;

  for (vector<int> wall: walls)
    grid[wall[0]][wall[1]] = 2;

  for (int i = 0; i < m; i ++) {
    bool g = 0;
    for (int j = 0; j < n; j ++) {
     if (grid[i][j] == 1) 
        g = 1;

      else if (grid[i][j] == 2) 
        g = 0;

      if (grid[i][j] == 0 && g)
        grid[i][j] = -1;
    }

    g = 0;
    for (int j = n - 1; j >= 0; j --) {
      if (grid[i][j] == 1)
        g = 1;

      else if (grid[i][j] == 2)
        g = 0;

      if (grid[i][j] == 0 && g)
        grid[i][j] = -1;
    }
  }

  for (int j = 0; j < n; j ++) {
    bool g = 0;
    for (int i = 0; i < m; i ++) {
      if (grid[i][j] == 1)
        g = 1;

      else if (grid[i][j] == 2)
        g = 0;

      if (grid[i][j] == 0 && g)
        grid[i][j] = -1;
    }

    g = 0;
    for (int i = m - 1; i >= 0; i --) {
      if (grid[i][j] == 1)
        g = 1;

      else if (grid[i][j] == 2)
          g = 0;

      if (grid[i][j] == 0 && g)
        grid[i][j] = -1;
    }
  }

  int res = 0;
  for (int i = 0; i < m; i ++)
    for (int j = 0; j < n; j ++)
      if (grid[i][j] == 0) res ++;

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int m, n;
    cin >> m >> n;

    int a;
    cin >> a;
    vector<vector<int>> guards(a, vector<int>(2, 0));
    for (int i = 0; i < a; i ++)
      cin >> guards[i][0] >> guards[i][1];

    int b;
    cin >> b;
    vector<vector<int>> walls(b, vector<int>(2, 0));
    for (int i = 0; i < b; i ++)
      cin >> walls[i][0] >> walls[i][1];

    int res = count_unguarded(m, n, guards, walls);
    cout << res << endl;
  }

  return 0;
}
