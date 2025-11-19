#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &nums) {
  vector<bool> freq(101, 0);

  int sum = 0, max_val = INT_MIN;
  for (int val : nums) {
    if (val > 0 && !freq[val]) {
      sum += val;

      freq[val] = 1;
    }

    max_val = max(max_val, val);
  }

  return max_val < 0 ? max_val : sum;
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

    int sum = max_sum(nums);
    cout << sum << '\n';
  }

  return 0;
}
