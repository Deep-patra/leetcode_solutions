#include <bits/stdc++.h>
using namespace std;

int min_sub_array(int target, vector<int> &nums) {
  int l = 0, r = nums.size() - 1;

  vector<int> pref(nums.size() + 1, 0);
  pref[0] = 0;

  for (int i = 0; i < nums.size(); i++)
    pref[i + 1] = pref[i] + nums[i];

  if (pref[nums.size()] < target)
    return 0;

  int i = 0, j = 0, res = nums.size();

  while (j < nums.size()) {
    int sum = pref[j + 1] - pref[i];

    if (sum >= target)
      res = min(res, (j - i) + 1);

    if (sum < target)
      j++;
    else
      i++;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, target;
    cin >> n >> target;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = min_sub_array(target, nums);
    cout << result << '\n';
  }

  return 0;
}
