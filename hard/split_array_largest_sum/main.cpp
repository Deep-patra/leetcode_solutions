#include <iostream>
#include <vector>
using namespace std;

// INFO: Solved 0ms runtime
int split_array(vector<int> &nums, int k) {

  int l = 0, r = 0, mid, res = INT_MAX;

  for (int val : nums) {
    l = max(l, val);
    r += val;
  }

  if (k == 1)
    return r;

  if (k == nums.size())
    return l;

  auto count_splits = [&](int mid) -> int {
    int splits = 0, temp = 0;

    for (int i = 0; i < nums.size(); i++) {

      if (temp + nums[i] > mid) {
        temp = 0;
        splits++;
      }

      temp += nums[i];
    }

    if (temp > 0)
      splits++;

    return splits;
  };

  while (l <= r) {
    mid = l + (r - l) / 2;

    int splits = count_splits(mid);

    if (splits > k)
      l = mid + 1;
    else {
      res = min(res, mid);
      r = mid - 1;
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

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = split_array(nums, k);
    cout << result << '\n';
  }

  return 0;
}
