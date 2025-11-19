#include <bits/stdc++.h>
using namespace std;

int r[4] = {-1, 1, 0, 0}, c[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>> &heights, vector<vector<int>> &grid, int i, int j) {
  int n = heights.size(), m = heights[0].size();

  grid[i][j] = 1;

  for (int k = 0; k < 4; k ++) {
    
    int row = i + r[k], col = j + c[k];

    if (row < 0 || col < 0 || row >= n || col >= m) continue;

    if (grid[row][col] == -1 && heights[row][col] >= heights[i][j])
      dfs(heights, grid, row, col);
  }  
}

vector<vector<int>> pacific_atlantic(vector<vector<int>> &heights) {
  int n = heights.size(), m = heights[0].size();

  vector<vector<int>> dp1(n, vector<int>(m, -1)), dp2(n, vector<int>(m, -1));

  for (int i = 0; i < n; i ++) {
    if (dp1[i][0] == -1)
      dfs(heights, dp1, i, 0);

    if (dp2[i][m - 1] == -1)
      dfs(heights, dp2, i, m - 1);
  }  

  for (int i = 0; i < m; i ++) {
    if (dp1[0][i] == -1)
      dfs(heights, dp1, 0, i);

    if (dp2[n - 1][i] == -1)
      dfs(heights, dp2, n - 1, i);
  }

  vector<vector<int>> res;

  for (int i = 0; i < n; i ++) 
    for (int j = 0; j < m; j ++)
      if (dp1[i][j] == 1 && dp2[i][j] == 1)
        res.push_back({ i, j });

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> heights[i][j];

    vector<vector<int>> coords = pacific_atlantic(heights);

    for (vector<int> c : coords)
      cout << c[0] << " " << c[1] << " ";
    cout << endl;
  }

  return 0;
}
