#include <bits/stdc++.h>
using namespace std;

int count_valid_selections(vector<int> &nums) {
  int n = nums.size(), cnt = 0;

  vector<int> pref_sum(n + 1, 0);

  for (int i = 0; i < n; i++)
    pref_sum[i + 1] = nums[i] + pref_sum[i];

  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {

      int left_sum = pref_sum[i] - pref_sum[0],
          right_sum = pref_sum[n] - pref_sum[i];

      if (left_sum == right_sum)
        cnt += 2;

      else if (abs(right_sum - left_sum) == 1)
        cnt += 1;
    }
  }

  return cnt;
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

    int res = count_valid_selections(nums);
    cout << res << endl;
  }

  return 0;
}
