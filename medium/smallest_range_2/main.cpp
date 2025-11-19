#include <bits/stdc++.h>
using namespace std;

int smallest_range(vector<int> &nums, int k) {
  int n = nums.size(), min_val = INT_MAX, max_val = INT_MIN;

  for (int val : nums) {
    min_val = min(min_val, val);
    max_val = max(max_val, val);
  }

  if (k >= (max_val - min_val))
    return max_val - min_val;

  int new_min = min(max_val - k, min_val + k),
      new_max = max(max_val - k, min_val + k);

  for (int val : nums) {

    int diff1 = max(val + k, new_max) - new_min;
    int diff2 = new_max - min(new_min, val - k);

    if (diff1 < diff2)
      new_max = max(val + k, new_max);
    else
      new_min = min(val - k, new_min);

    cout << "new max => " << new_max << " new min => " << new_min << endl;
  }

  return new_max - new_min;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = smallest_range(nums, k);
    cout << res << '\n';
  }

  return 0;
}
