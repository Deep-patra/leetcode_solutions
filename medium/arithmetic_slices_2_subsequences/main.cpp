#include <bits/stdc++.h>  
using namespace std;

int number_of_arithmetic_subsequences(vector<int> &nums) {
  int n = nums.size(), res = 0;

  vector<map<int, int>> dp(n);

  for (int i = 1; i < n; i ++) {
    
    for (int j = i - 1; j >= 0; j --) {

      int diff = nums[i] - nums[j];

      if (dp[j].count(diff)) {

        dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);

        res += ((dp[j][diff] + 1) - 3) + 1;
      } else 
        dp[i][diff] = 2;

    }

  }

  return res;
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

    int res = number_of_arithmetic_subsequences(nums);
    cout << res << '\n';
  }

  return 0;
}
