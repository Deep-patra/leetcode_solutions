#include <bits/stdc++.h>
using namespace std;

// TODO: Complete the Implementation
int max_subarray_sum_circular(vector<int> &nums) {
  int n = nums.size();


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

    int res = max_subarray_sum_circular(nums);
    cout << res << '\n';
  }

  return 0;
}
