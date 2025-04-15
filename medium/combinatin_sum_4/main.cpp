#include <iostream>
#include <vector>
using namespace std;

int combination_sum_4(vector<int> &nums, int target) {
  vector<int> dp(target + 1, 0);

  dp[0] = 1;

  for (int i = 1; i <= target; i++) {
    for (int num: nums) {
      if ((i - num) >= 0) 
        dp[i] += dp[i - num];
    }
  }

  for (int way : dp)
    cout << way << ' ';
  cout << '\n';

  return dp[target];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, target;
    cin >> n >> target;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = combination_sum_4(nums, target);
    cout << result << '\n';
  }

  return 0;
}
