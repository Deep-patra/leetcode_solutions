#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maximum_triplet_value(vector<int> &nums) {
  ll result = 0;
  int maximum = nums[0], max_diff = 0;

  for (int i = 1; i < nums.size() - 1; i ++) {
    max_diff = max(max_diff, maximum - nums[i]);
    result = max(result, max_diff * nums[i + 1] * 1LL);

    maximum = max(maximum, nums[i]);
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    ll result = maximum_triplet_value(nums);
    cout << result  << '\n';
  }

  return 0;
}
