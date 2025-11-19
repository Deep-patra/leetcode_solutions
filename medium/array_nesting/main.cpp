#include <bits/stdc++.h>
using namespace std;

int array_nesting(vector<int> &nums) {
  int n = nums.size(), max_size = INT_MIN;

  vector<int> dp(n, -1);

  for (int i = 0; i < n; i++) {
    if (dp[i] == -1) {
      int curr = i, size = 1;
      while (dp[curr] == -1) {
        dp[curr] = size++;

        max_size = max(dp[curr], max_size);
        curr = nums[curr];
      }
    }
  }

  return max_size;
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

    int result = array_nesting(nums);
    cout << result << '\n';
  }

  return 0;
}
