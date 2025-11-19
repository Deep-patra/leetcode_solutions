#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// TODO: Complete the Implementation
ll subarray_ranges(vector<int> &nums) { int n = nums.size(); }

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

    ll res = subarray_ranges(nums);
    cout << res << endl;
  }

  return 0;
}
