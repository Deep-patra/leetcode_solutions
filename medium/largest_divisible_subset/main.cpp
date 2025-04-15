#include <bits/stdc++.h>
using namespace std;

vector<int> largest_divisible_subset(vector<int> &nums) {
  int n = nums.size(), max_index = 0, longest = 1;

  sort(nums.begin(), nums.end());

  vector<int> dp(n, 1), p(n, -1), result;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {

      if (nums[i] % nums[j] == 0) {
        if (dp[j] + 1 > dp[i]) {
          p[i] = j;

          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    if (dp[i] > longest) {
      longest = dp[i];
      max_index = i;
    }
  }

  result.resize(longest);

  int index = 0;
  for (int i = max_index; i != -1; i = p[i])
    result[longest - (index ++) - 1] = nums[i];


  return result;
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

    vector<int> result = largest_divisible_subset(nums);

    for (int val : result)
      cout << val << ' ';
    cout << '\n';
  }

  return 0;
}
