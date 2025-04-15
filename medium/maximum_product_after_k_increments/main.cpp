#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int find_max(vector<int> &nums) {
  int max_val = nums[0];

  for (int val : nums)
    max_val = max(max_val, val);

  return max_val;
}

int maximum_product(vector<int> &nums, int k) {
  
  int max_val = find_max(nums);

  vector<int> freq(max_val + k + 1, 0);

  for (int val : nums)
    freq[val] ++;

  for (int i = 0; i < freq.size(); i ++) {
    if (k < 1) break;

    int f = freq[i];

    if (f == 0) continue;

    if (f <= k) {
      freq[i + 1] += f;
      freq[i] = 0;
      k -= f;
    } else {
      freq[i] -= k;
      freq[i + 1] += k;
      k = 0;
    }
  }

  if (freq[0] > 0) return 0;

  int prod = 1;
  for (int i = 1; i < freq.size(); i ++) {
    if (freq[i] > 0) {
      while (freq[i] > 0) {
        prod *= i;
        prod %= MOD;

        freq[i] --;
      }
    }
  }

  return prod;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int result = maximum_product(nums, k);
    cout << result << '\n';
  }

  return 0;
}
