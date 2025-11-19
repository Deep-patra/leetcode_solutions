#include <bits/stdc++.h>
using namespace std;

// INFO: Complete the Implmentation
vector<int> good_indices(vector<int> &nums, int k) {
  int n = nums.size();

  if (k == 0) {
    sort(nums.begin(), nums.end());
    return nums;
  }

  vector<bool> t(n, 0);

  int l = 0, r = 0;
  while (r < n) {

  }
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

    vector<int> res = good_indices(nums, k);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
