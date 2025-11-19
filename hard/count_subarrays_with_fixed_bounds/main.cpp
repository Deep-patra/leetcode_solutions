#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// TODO: Complete the implementation
ll count_subarrays(vector<int> &nums, int minK, int maxK) {
  ll res = 0;

  int n = nums.size(), l = 0, r = 0, valid_index = 0, min_freq = nums[0] == minK ? 1 : 0,
      max_freq = nums[0] == maxK ? 1 : 0;

  while (r < n && l <= r) {

    if (nums[r] < minK || nums[r] > maxK) {
      l = ++r;
      valid_index = r;

      if (r < n) {
        min_freq = nums[r] == minK;
        max_freq = nums[r] == maxK;
      }

      continue;
    }

    if (min_freq > 0 && max_freq > 0) {
    
      if (nums[l] != minK && nums[l] != maxK) {
        valid_index = l;

        l ++;
        continue;
      }

      res += (l - valid_index + 1);
    }

    r ++;

    if (r < n) {
      min_freq = nums[r] == minK ? min_freq + 1 : min_freq;
      max_freq = nums[r] == maxK ? max_freq + 1 : max_freq;
    }

  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, minK, maxK;
    cin >> n >> minK >> maxK;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    ll result = count_subarrays(nums, minK, maxK);
    cout << result << '\n';
  }

  return 0;
}
