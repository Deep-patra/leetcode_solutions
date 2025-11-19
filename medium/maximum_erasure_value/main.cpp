#include <bits/stdc++.h>
using namespace std;

int maximum_erasure_value(vector<int> &nums) {
  int n = nums.size();

  int l = 0, r = 0, sum = 0, curr_sum = 0;

  vector<int> freq(10001, 0);

  while (r < n) {
    if (freq[nums[r]] > 0) {

      while (l <= r && freq[nums[r]] > 0) {
        freq[nums[l]]--;
        curr_sum -= nums[l];
        l++;
      }
    }

    freq[nums[r]]++;
    curr_sum += nums[r];

    sum = max(sum, curr_sum);

    r++;
  }

  return sum;
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

    int res = maximum_erasure_value(nums);
    cout << res << '\n';
  }

  return 0;
}
