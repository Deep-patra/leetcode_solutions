#include <bits/stdc++.h>
using namespace std;

// Using Kadane's Algorithm
int longest_subarray(vector<int> &nums) {
  int n = nums.size(), res = 1;

  int curr = nums[0], max_and = nums[0], len = 1;
  for (int i = 1; i < n; i++) {

    if ((curr & nums[i]) >= nums[i] && (curr & nums[i]) >= curr)
      len++;
    else
      len = 1;

    curr = max(curr & nums[i], nums[i]);

    if (curr >= max_and) {
      if (curr == max_and)
        res = max(res, len);
      else
        res = len;
    }

    max_and = max(max_and, curr);
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

    int res = longest_subarray(nums);
    cout << res << '\n';
  }

  return 0;
}
