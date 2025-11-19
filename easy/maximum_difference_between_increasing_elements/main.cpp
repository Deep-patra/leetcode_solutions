#include <bits/stdc++.h>
using namespace std;

// Using A Monotonic Stack
int maximum_difference(vector<int> &nums) {
  
  int n = nums.size(), minimum = nums[0], diff = -1;

  for (int i = 1; i < n; i ++) {

    if (nums[i] > minimum)
      diff = max(nums[i] - minimum, diff);

    minimum = min(minimum, nums[i]);
  }

  return diff;
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

    int res = maximum_difference(nums);
    cout << res << '\n';
  }

  return 0;
}
