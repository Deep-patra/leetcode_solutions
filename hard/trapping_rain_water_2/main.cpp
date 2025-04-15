#include <iostream>
#include <vector>
using namespace std;

// For debugging purposes
void print_matrix(vector<vector<int>> &m) {
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[0].size(); j++)
      cout << m[i][j] << " ";

    cout << '\n';
  }

  cout << '\n';
}

// The dynamic programming approach
// if the surrounding blocks are greater than the inner block
// then the amount water is the difference between the inner block height and
// the smallest block in the surrounding.
// INFO: 17ms rumtime beats 96.28%
// TODO: Try a graph flow algorithm approach
int trapping_rain_water(vector<vector<int>> &heightMap) {
  int m = heightMap.size(), n = heightMap[0].size();

  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 1; i < m - 1; i++)
    for (int j = 1; j < n - 1; j++)
      dp[i][j] = INT_MAX;

  while (true) {

    vector<vector<int>> prev_state(dp);

    // forward pass
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {

        int top = heightMap[i - 1][j] + dp[i - 1][j],
            left = heightMap[i][j - 1] + dp[i][j - 1], curr = heightMap[i][j];

        if (top >= curr && left >= curr)
          dp[i][j] = min(dp[i][j], min(top, left) - curr);
        else
          dp[i][j] = 0;
      }
    }

    // Backward pass
    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        int bottom = heightMap[i + 1][j] + dp[i + 1][j],
            right = heightMap[i][j + 1] + dp[i][j + 1], curr = heightMap[i][j];

        if (bottom >= curr && right >= curr)
          dp[i][j] = min(dp[i][j], min(bottom, right) - curr);
        else
          dp[i][j] = 0;
      }
    }

    if (prev_state == dp)
      break;
  }

  int result = 0;

  // add the values to get the trapped water
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      result += dp[i][j];

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> height_map(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> height_map[i][j];

    int result = trapping_rain_water(height_map);
    cout << result << '\n';
  }

  return 0;
}
