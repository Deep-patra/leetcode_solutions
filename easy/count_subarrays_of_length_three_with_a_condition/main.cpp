#include <bits/stdc++.h>
using namespace std;

int count_subarrays(vector<int> &nums) {
  int l = 0, r = 2, mid = 1, res = 0;

  while (r < nums.size() && l < r) {

    if ((nums[l] + nums[r]) == nums[mid] / 2)
      res++;

    l++;
    r++;
    mid++;
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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = count_subarrays(nums);
    cout << res << '\n';
  }

  return 0;
}
