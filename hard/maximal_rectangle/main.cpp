#include <iostream>
#include <vector>
using namespace std;

// TODO: Complete the implementation
int maximal_rectangle(vector<vector<char>> &matrix) {
  int m = matrix.size(), n = matrix[0].size(), max_rect = INT_MIN;

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // finding the maximum rectangle when moving horizontally
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == '1') 
        dp[i][j] = j > 0 ? dp[i][j - 1] + 1 : 1;

      max_rect = max(max_rect, dp[i][j]);
    }
  }


  // finding the maximum rectangle when moving vertically
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[j][i] == '1') 
        dp[j][i] = j > 0 ? dp[j - 1][i] + 1 : 1;

      max_rect = max(max_rect, dp[j][i]);
    }
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if ()
    }
  }


  return max_rect;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int m, n;
    cin >> m, n;

    vector<vector<char>> matrix(m, vector<char>(n, ''));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j ++)
        cin >> matrix[i][j];


    int result = maximal_rectangle(matrix);
    cout << result << '\n';
  }

  return 0;
}
