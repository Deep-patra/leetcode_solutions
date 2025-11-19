#include <bits/stdc++.h>
using namespace std;

int parition_array(vector<int> &nums, int k) {
  int res = 0, n = nums.size();

  sort(nums.begin(), nums.end());

  int start = nums[0];
  for (int i = 1; i < n; i ++) {
    if (nums[i] - start > k) {
      start = nums[i];
      res ++;
    }
  }

  return res + 1;
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

    int res = parition_array(nums, k);
    cout << res << '\n';
  }

  return 0;
}
