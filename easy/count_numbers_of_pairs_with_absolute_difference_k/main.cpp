#include <bits/stdc++.h>
using namespace std;

int count_k_difference(vector<int> &nums, int k) {
  int n = nums.size(), res = 0;

  for (int i = 0; i < n; i ++) {
    for (int j = i + 1; j < n; j ++) {
      if (abs(nums[i] - nums[j])) res ++;
    }
  }

  return res;
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

    int res = count_k_difference(nums, k);
    cout << res << '\n';
  }

  return 0;
}
