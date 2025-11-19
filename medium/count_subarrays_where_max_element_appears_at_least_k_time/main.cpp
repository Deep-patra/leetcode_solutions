#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll count_subarrays(vector<int> &nums, int k) {
  ll res = 0;

  int max_elem = nums[0];
  for (int val : nums)
    max_elem = max(max_elem, val);

  int l = 0, r = 0, n = nums.size(), max_freq = nums[r] == max_elem ? 1 : 0;

  while (r < n && l <= r) {

    if (max_freq >= k) {

      if (max_freq > k) {
        if (nums[l] == max_elem)
          max_freq--;

        l++;
        continue;
      }

      while (nums[l] != max_elem)
        l++;

      res += l + 1;
    }

    r++;

    if (r < n && nums[r] == max_elem)
      max_freq++;
  }

  return res;
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

    ll res = count_subarrays(nums, k);
    cout << res << '\n';
  }

  return 0;
}
