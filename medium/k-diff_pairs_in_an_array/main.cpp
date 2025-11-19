#include <bits/stdc++.h>
using namespace std;

int find_pairs(vector<int> &nums, int k) {
  int n = nums.size(), res = 0;

  sort(nums.begin(), nums.end());

  unordered_map<int, int> m;

  for (int val : nums)
    m[val]++;

  int prev = INT_MIN;
  for (int val : nums) {

    if (prev == val)
      continue;

    m[val]--;

    if (m[val] == 0)
      m.erase(val);

    if (m.find(val + k) != m.end()) {
      res++;
    }

    prev = val;
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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = find_pairs(nums, k);
    cout << res << '\n';
  }

  return 0;
}
