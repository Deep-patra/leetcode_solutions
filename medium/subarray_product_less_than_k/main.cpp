#include <bits/stdc++.h>
using namespace std;

// INFO: FIND SUBARRAYS WHICH ARE LESS THAN K, NOT EQUAL TO K!!!
int num_subarray_product_less_than_k(vector<int> &nums, int k) {
  int n = nums.size(), res = 0, i = 0, j = 0, curr_prod = 1;

  if (k == 0)
    return 0;

  while (i <= j && j < n) {

    curr_prod *= nums[j];

    if (curr_prod == k) {

      res++;

      curr_prod /= nums[i++];

      if (i == j)
        j++;

    } else {

      if (curr_prod < k)
        j++;

      else
        curr_prod /= nums[i++];
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

    int res = num_subarray_product_less_than_k(nums, k);
    cout << res << endl;
  }

  return 0;
}
