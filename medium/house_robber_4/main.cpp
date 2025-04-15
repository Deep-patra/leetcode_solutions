#include <bits/stdc++.h>
using namespace std;

// INFO: Using Binary Search Approach
int min_capability(vector<int> &nums, int k) {
  int n = nums.size();

  if (n <= 2)
    return n == 2 ? max(nums[0], nums[1]) : nums[0];

  vector<int> right_min(n, INT_MAX);

  int minimum = nums[n - 1], j = n - 1;
  for (int i = n - 3; i >= 0; i --) {
    right_min[i] = minimum;

    if (nums[--j] < minimum)
      minimum = nums[j];
  }

  minimum = INT_MAX;
  for (int i = 0; i < n; i++) 
    minimum = min(minimum, max(nums[i], right_min[i]));

  return minimum;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = min_capability(nums, k);
    cout << result << '\n';
  }

  return 0;
}
