#include <bits/stdc++.h>
using namespace std;

int maximum_length(vector<int> &nums, int k) {
  int n = nums.size(), res = 0;

  vector<vector<int>> dp(n, vector<int>(k, 1));

  for (int i = 1; i < n; i ++) {
    for (int j = i - 1; j >= 0; j --) {
      int m = (nums[i] + nums[j]) % k;
      dp[i][m] = max(dp[i][m], dp[j][m] + 1);

      res = max(res, dp[i][m]);
    }
  }

  return res;
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

    int res = maximum_length(nums, k);
    cout << res << endl;
  }

  return 0;
}
