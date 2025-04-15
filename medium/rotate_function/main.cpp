#include <bits/stdc++.h>
using namespace std;

int max_rotate_function(vector<int> &nums) {
  int n = nums.size(), sum = 0, result = INT_MIN;

  if (n == 1) return 0;

  else if (n == 2) return max(nums[0], nums[1]);

  vector<int> dp(n);

  for (int i = 0; i < n; i ++) {
    sum += nums[i];
    dp[0] += nums[i] * i;
  }

  for (int i = 1; i < n; i ++) {
    dp[i] = dp[i - 1] + (sum - (n * nums[n - i]));
    result = max(result, dp[i]);
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int result = max_rotate_function(nums);
    cout << result << '\n';
  }

  return 0;
}
