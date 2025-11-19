#include <bits/stdc++.h>
using namespace std;

int freq[(int)1e5 + 1], last[(int)1e5 + 1];

int max_frequency(vector<int> &nums, int k) {
  int n = nums.size(), max_val = INT_MIN, max_freq = 1;

  memset(freq, 0, sizeof(freq));

  for (int val : nums) {
    freq[val]++;

    max_freq = max(max_freq, freq[val]);
    max_val = max(max_val, val);
  }

  for (int i = 0, elem = -1; i <= max_val; i++) {

    last[i] = elem;

    if (freq[i] > 0) {

      int t = k, f = freq[i], num = last[i];
      while (num != -1 && t >= (i - num)) {
        int mul = t / (i - num);

        f += min(freq[num], mul);
        t -= (i - num) * min(freq[num], mul);

        num = last[num];
      }

      max_freq = max(max_freq, f);
      elem = i;
    }
  }

  return max_freq;
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

    int freq = max_frequency(nums, k);
    cout << freq << endl;
  }

  return 0;
}
