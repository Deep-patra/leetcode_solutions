#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int comb[100001];
bool initialized = 0;

// INFO: Using Sliding Window
// INFO: Solved but a bit slow
ll count_good_subarrays(vector<int> &nums, int k) {

  if (!initialized) {
    comb[0] = comb[1] = 0;
    comb[2] = 1;

    for (int i = 3; i < 100001; i++)
      comb[i] = (int)(((ll)i * (ll)comb[i - 1]) / (i - 2));
  }

  int l = 0, r = 0, n = nums.size();
  ll curr = 0;

  unordered_map<int, int> freq;
  freq[nums[l]]++;

  ll res = 0;
  while (l <= r) {
    if (l == r) {
      if (r == n - 1)
        break;

      r += 1;
      curr -= comb[freq[nums[r]]];

      freq[nums[r]]++;
      curr += comb[freq[nums[r]]];
    }

    if (curr >= (ll)k) {
      res += (n - r);

      curr -= comb[freq[nums[l]]];

      // move the left pointer by one index to the right
      freq[nums[l++]]--;
      curr += comb[freq[nums[l - 1]]];
    }

    // if the current pairs are less than k
    // move the right pointer to the right by one index
    else {
      if (r == n - 1)
        break;

      r += 1;
      curr -= comb[freq[nums[r]]];

      freq[nums[r]]++;
      curr += comb[freq[nums[r]]];
    }
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

    ll result = count_good_subarrays(nums, k);
    cout << result << '\n';
  }

  return 0;
}
