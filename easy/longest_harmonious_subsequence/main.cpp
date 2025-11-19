#include <bits/stdc++.h>
using namespace std;

int find_lhs(vector<int> &nums) {
  int n = nums.size(), res = 0;

  unordered_map<int, int> m;

  for (int i = 0; i < n; i++)
    m[nums[i]]++;

  for (int i = 0; i < n; i++) {
    if (m.find(nums[i] - 1) != m.end())
      res = max(res, m[nums[i]] + m[nums[i] - 1]);
    else if (m.find(nums[i] + 1) != m.end())
      res = max(res, m[nums[i]] + m[nums[i] + 1]);
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

    int res = find_lhs(nums);
    cout << res << '\n';
  }

  return 0;
}
