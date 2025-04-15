#include <bits/stdc++.h>
using namespace std;

int remove_boxes(vector<int> &boxes) {
  int n = boxes.size();

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      if (boxes[j] == boxes[i + j])
        dp[j][i] = 2 * 2;

      for (int k = j; k < i + j; k++) {
        dp[i + j][i] = max(dp[i + j][i], );
      }
    }
  }

  return dp[0][n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> boxes(n);
    for (int i = 0; i < n; i++)
      cin >> boxes[i];

    int result = remove_boxes(boxes);
    cout << result << '\n';
  }

  return 0;
}
