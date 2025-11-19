#include <bits/stdc++.h>
using namespace std;

int subarray_sum(vector<int> &nums, int k) {
  int n = nums.size(), res = 0;

  int i = 0, j = 0, curr_sum = 0;
  while (i <= j && j < n) {

    curr_sum += nums[j];

    if (curr_sum == k) {

      res++;

      curr_sum -= nums[i++];

      if (i == j)
        j++;

    } else {

      if (curr_sum < k)
        j++;

      else
        curr_sum -= nums[i++];
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

    int res = subarray_sum(nums, k);
    cout << res << endl;
  }

  return 0;
}
