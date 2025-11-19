#include <bits/stdc++.h>
using namespace std;

int smallest_divisor(vector<int> &nums, int threshold) {
  int n = nums.size(), max_num = nums[0];

  for (int val : nums)
    max_num = max(max_num, val);

  auto get_sum = [&](int d) -> int {
    int sum = 0;
    for (int val : nums)
      sum += ceil(((double)val / (double)d));

    return sum;
  };

  int l = 1, h = max_num, res = max_num;
  while (l <= h) {
    int mid = l + (h - l) / 2;

    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += ceil((double)nums[i] / (double)mid);

    if (sum > threshold)
      l = mid + 1;

    else {
      h = mid - 1;
      res = mid;
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, threshold;
    cin >> n >> threshold;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = smallest_divisor(nums, threshold);
    cout << res << endl;
  }

  return 0;
}
