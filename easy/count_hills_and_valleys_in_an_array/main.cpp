#include <bits/stdc++.h>
using namespace std;

int count_hill_valley(vector<int> &nums) {
  int n = nums.size(), res = 0;

  for (int i = 1; i < n - 1; i++) {

    int l = i, r = i;

    while (l >= 0 && nums[l] == nums[i])
      l--;

    while (r < n && nums[r] == nums[i])
      r++;

    if (l < 0 || r >= n)
      continue;

    if (nums[l] > nums[i] && nums[r] > nums[i] ||
        nums[l] < nums[i] && nums[r] < nums[i])
      res++;

    i = r - 1;
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

    int res = count_hill_valley(nums);
    cout << res << '\n';
  }

  return 0;
}
