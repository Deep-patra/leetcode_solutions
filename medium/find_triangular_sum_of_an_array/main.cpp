#include <bits/stdc++.h>
using namespace std;

int triangular_sum(vector<int> &nums) {
  int n = nums.size();

  vector<int> dp(nums.begin(), nums.end());

  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++)
      dp[j] = (dp[j] + dp[j + 1]) % 10;
  }

  return dp[0];
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

    int res = triangular_sum(nums);
    cout << res << endl;
  }

  return 0;
}
