#include <bits/stdc++.h>
using namespace std;

int longest_subarray(vector<int> &nums) {
  int n = nums.size(), res = 0;

  for (int i = 0, j = 0, last_idx = -1; i < n && j < n; i++) {

    if (nums[i] == 0) {

      if (last_idx != -1 && j <= last_idx) {

        res = max(res, (i - j - 1));

        j = last_idx + 1;

        last_idx = i;
        continue;
      }

      last_idx = i;
    }

    int l = i - j;

    res = max(res, l);
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

    int res = longest_subarray(nums);
    cout << res << '\n';
  }

  return 0;
}
