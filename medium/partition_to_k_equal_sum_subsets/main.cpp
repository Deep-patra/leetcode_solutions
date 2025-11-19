#include <bits/stdc++.h>  
using namespace std;

// INFO: Will be solved with bitmask DP.
bool can_parition_k_subsets(vector<int> &nums, int k) {
  int n = nums.size(), sum = 0;

  for (int val : nums) sum += val;

  if (sum % k != 0) return 0;

  vector<int> dp((sum / k) + 1, 0);

  for (int i = 0; i < n; i ++) {

    if (nums[i] > (sum / k)) return 0;

    for (int j = (sum / k) - nums[i]; j >= 0; j --) {
      if (dp[j] > 0) 
        dp[j + nums[i]] ++;
    }

    dp[nums[i]] ++;
  }

  for (int val : dp)
    cout << val << " ";
  cout << endl;

  return dp[sum / k] == k;
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

    bool res = can_parition_k_subsets(nums, k);
    cout << res << endl;
  }

  return 0;
} 
