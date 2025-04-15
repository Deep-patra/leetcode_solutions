#include <bits/stdc++.h>
using namespace std;

// INFO: Using Kadane's algorithm
int max_absolute_sum(vector<int> &nums) {
  int max_sum = INT_MIN, min_sum = INT_MAX;
  int curr_max = nums[0], curr_min = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    curr_max = max(nums[i], curr_max + nums[i]);
    curr_min = min(nums[i], curr_min + nums[i]);

    max_sum = max(curr_max, max_sum);
    min_sum = min(curr_min, min_sum);
  }

  return max(max_sum, abs(min_sum));
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = max_absolute_sum(nums);
    cout << result << '\n';
  }

  return 0;
}
