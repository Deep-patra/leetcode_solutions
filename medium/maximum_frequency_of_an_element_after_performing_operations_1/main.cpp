#include <bits/stdc++.h>
using namespace std;

int max_frequency(vector<int> &nums, int k, int numOperations) {
  int n = nums.size(), max_val = INT_MIN;

  for (int val : nums)
    max_val = max(max_val, val);

  vector<int> freq(max_val + k + 2, 0), diff(max_val + k + 2, 0);

  for (int val : nums) {
    freq[val]++;

    diff[max(0, val - k)]++;
    diff[val + k + 1]--;
  }

  int max_freq = 0;
  for (int i = 0, curr = 0; i < max_val + k + 2; i++) {
    curr += diff[i];

    max_freq = max(max_freq, freq[i] + min(numOperations, curr - freq[i]));
  }

  return max_freq;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k, num_operations;
    cin >> n >> k >> num_operations;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = max_frequency(nums, k, num_operations);
    cout << res << endl;
  }

  return 0;
}
