#include <bits/stdc++.h>
using namespace std;

int minimum_subarray(vector<int> &nums, int k) {
  int n = nums.size();

  vector<int> one_freq(32, 0);

  auto add_val = [&](int val) {
    for (int i = 0; i < 32; i++) {
      if (nums[i] & (1 << i))
        one_freq[i]++;
    }
  };

  auto remove_val = [&](int val) -> int {
    int new_val = 0;

    for (int i = 0; i < 32; i++) {
      if (val & (1 << i))
        one_freq[i]--;

      new_val |= one_freq[i] > 0 ? (1 << i) : 0;
    }

    return new_val;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 32; j++) {
      if (nums[i] & (1 << j))
        one_freq[j]++;
    }
  }

  int l = 0, r = n - 1;
  while (l <= r) {
    int new_l = l, new_r = r;

    if (remove_val(nums[l]) > k)
      l++;
    else 
      add_val(nums[l]);

    if (remove_val(nums[r]) > k)
      r--;
    else 
      add_val(nums[r]);

    if (new_l == l && new_r == r)
      break;
  }

  return r - l + 1;
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

    int res = minimum_subarray(nums, k);
    cout << res << '\n';
  }

  return 0;
}
