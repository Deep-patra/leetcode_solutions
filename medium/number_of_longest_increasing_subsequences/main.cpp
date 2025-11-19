#include <bits/stdc++.h>
using namespace std;

int find_number_of_lis(vector<int> &nums) {
  int n = nums.size(), max_seq = 0;

  vector<int> lis(2001, 0);
  vector<pair<int, int>> dp(n, {1, 1});

  lis[1] = n;

  for (int i = 1; i < n; i++) {

    for (int j = i - 1; j >= 0; j--) {

      if (nums[i] > nums[j]) {

        if (dp[i].first < (dp[j].first + 1)) {

          dp[i] = make_pair(dp[j].first + 1, 1);
          lis[dp[i].first] += dp[j].second;

        } else if (dp[i].first == (dp[j].first + 1)) {
          dp[i].second += dp[j].second;
          lis[dp[i].first] += dp[j].second;
        }
      }
    }
    max_seq = max(max_seq, dp[i].first);
  }

  return lis[max_seq];
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

    int res = find_number_of_lis(nums);
    cout << res << '\n';
  }

  return 0;
}
