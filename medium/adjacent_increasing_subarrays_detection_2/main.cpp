#include <bits/stdc++.h>
using namespace std;

int max_increasing_subarrays(vector<int> &nums) {
  int n = nums.size(), res = 1, prev = nums[n - 1], l = 1;
  nums[n - 1] = 1;

  for (int i = n - 2; i >= 0; i--) {
    int p = nums[i];

    if (nums[i] < prev) {
      l = nums[i + 1] + 1;
    } else
      l = 1;

    nums[i] = l;

    res = max(res, l >> 1);

    if ((i + 2 * l) <= n && nums[i] <= nums[i + l])
      res = max(res, nums[i]);

    prev = p;
  }

  return res;
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

    int res = max_increasing_subarrays(nums);
    cout << res << endl;
  }

  return 0;
}
