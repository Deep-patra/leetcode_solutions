#include <bits/stdc++.h>
using namespace std;

// INFO: Runtime is too high about 180 ms.. needs an runtime of 5ms
// TODO: Implement a efficient implementation
int length_of_longest_subsequences(vector<int> &nums, int target) {
  int n = nums.size();

  vector<int> dp1(target + 1, 0), dp2(target + 1, 0);

  if (nums[0] <= target)
    dp1[nums[0]] = 1;

  for (int i = 1; i < n; i++) {

    if (nums[i] > target) {
      continue;
    }

    for (int j = target; j >= 0; j--) {
      if (j + nums[i] <= target && dp1[j] > 0)
        dp2[nums[i] + j] = max(dp2[nums[i] + j], dp1[j] + 1);

      dp2[j] = max(dp2[j], dp1[j]);
    }

    dp2[nums[i]] = max(dp2[nums[i]], 1);

    dp1 = move(dp2);
    dp2 = vector<int>(target + 1, 0);
  }

  return dp1[target] == 0 ? -1 : dp1[target];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = length_of_longest_subsequences(nums, target);
    cout << res << endl;
  }

  return 0;
}
