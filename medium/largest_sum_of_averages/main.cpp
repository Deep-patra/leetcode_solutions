#include <bits/stdc++.h>
using namespace std;

const double EPSILON = numeric_limits<double>::epsilon();

double largest_sum_of_averages(vector<int> &nums, int k) {
  int n = nums.size();

  vector<vector<double>> dp(n, vector<double>(k + 1, 0));

  vector<int> pref(n + 1, 0);
  for (int i = 0; i < n; i++)
    pref[i + 1] = pref[i] + nums[i];

  for (int i = 0; i < n; i++)
    dp[i][1] = ((double)(pref[i + 1]) / (double)(i + 1));

  for (int j = 2; j <= k; j++) {
    for (int i = j - 1; i < n; i++) {

      double max_avg = 0.0;

      for (int p = j - 1; p <= i; p++)
        max_avg = max(max_avg, dp[p - 1][j - 1] + (double)(pref[i + 1] - pref[p]) /
                                                  (double)((i - p) + 1));

      dp[i][j] = max_avg;
    }
  }

  return dp[n - 1][k];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    double result = largest_sum_of_averages(nums, k);
    cout << result << '\n';
  }

  return 0;
}
