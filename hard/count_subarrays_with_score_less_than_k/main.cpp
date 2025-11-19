#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll count_subarrays(vector<int> &nums, ll k) {
  ll res = 0, sum = nums[0];

  int l = 0, r = 0, n = nums.size();

  while (r < n && l <= r) {
    if (1LL * sum * (r - l + 1) < k) {
      res += (r - l + 1);

      r++;
      if (r < n)
        sum += nums[r];
    } else {
      sum -= nums[l];

      if (l == r) {
        l = ++r;
        if (r < n)
          sum = nums[r];
        continue;
      }

      l++;
    }
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

    ll k;
    cin >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    ll res = count_subarrays(nums, k);
    cout << res << '\n';
  }

  return 0;
}
