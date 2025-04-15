#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {

  int curr = matrix[i][j];
  int longest = 1;

  if (dp[i][j] != -1)
    return;

  if (j < matrix[0].size() - 1 && matrix[i][j + 1] < curr) {
    dfs(matrix, dp, i, j + 1);
    longest = max(longest, dp[i][j + 1] + 1);
  }

  if (j > 0 && matrix[i][j - 1] < curr) {
    dfs(matrix, dp, i, j - 1);
    longest = max(longest, dp[i][j - 1] + 1);
  }

  if (i > 0 && matrix[i - 1][j] < curr) {
    dfs(matrix, dp, i - 1, j);
    longest = max(longest, dp[i - 1][j] + 1);
  }

  if (i < matrix.size() - 1 && matrix[i + 1][j] < curr) {
    dfs(matrix, dp, i + 1, j);
    longest = max(longest, dp[i + 1][j] + 1);
  }

  dp[i][j] = longest;

  return;
}

int longest_increasing_path(vector<vector<int>> &matrix) {
  int m = matrix.size(), n = matrix[0].size();

  vector<vector<int>> dp(m, vector<int>(n, -1));

  int result = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] == -1)
        dfs(matrix, dp, i, j);

      result = max(result, dp[i][j]);
    }
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

    int result = longest_increasing_path(matrix);

    cout << result << '\n';
  }

  return 0;
}
