#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> &nums, int x, int i, int j, int curr, int &steps,
         int curr_steps = 0) {

  if (curr_steps > steps || i > j)
    return 0;

  if (curr == x) {
    steps = min(curr_steps, steps);
    return 1;
  }

  if (i == j) {
    steps = min(curr_steps + 1, steps);
    return x == (curr + nums[i]);
  }

  bool l = dfs(nums, x, i + 1, j, curr + nums[i], steps, curr_steps + 1);
  bool r = dfs(nums, x, i, j - 1, curr + nums[j], steps, curr_steps + 1);

  return l || r;
}

int min_operations(vector<int> &nums, int x) {

  int steps = INT_MAX;

  if (dfs(nums, x, 0, nums.size() - 1, 0, steps))
    return steps;

  return -1;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = min_operations(nums, x);
    cout << res << endl;
  }

  return 0;
}
