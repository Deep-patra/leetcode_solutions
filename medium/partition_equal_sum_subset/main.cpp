#include <bits/stdc++.h>
using namespace std;

bool dp[10001];

bool can_partition(vector<int> &nums) {
  memset(dp, 0, sizeof(dp));

  dp[0] = 1;

  int sum = 0;

  for (int val : nums)
    sum += val;

  if (sum & 1)
    return false;

  for (int i = 0; i < nums.size(); i++) {

    for (int j = (sum >> 1) - nums[i]; j >= 0; j--)
      if (dp[j])
        dp[j + nums[i]] = 1;

    if (dp[(sum >> 1)])
      return true;
  }

  return false;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    bool result = can_partition(nums);
    cout << result << '\n';
  }

  return 0;
}
