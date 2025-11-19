#include <bits/stdc++.h>  
using namespace std;

int length_of_lis(vector<int> &nums, int k) {
  int n = nums.size(), max_sq = 0;

  vector<int> dp(n, 1);

  for (int i = 1; i < n; i ++) {

    for (int j = i - 1; j >= 0; j --) {

      int diff = nums[i] - nums[j];

      if (diff > 0 && diff <= k) 
        dp[i] = max(dp[i], dp[j] + 1);

    }

    max_sq = max(max_sq, dp[i]);
  }

  return max_sq;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int res = length_of_lis(nums, k);
    cout << res << '\n';
  }

  return 0;
}
