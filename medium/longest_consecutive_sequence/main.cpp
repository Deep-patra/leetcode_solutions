#include <bits/stdc++.h>
using namespace std;

int find_len(unordered_map<int, int> &m, int val) {
  if (m[val] != 0)
    return m[val];

  m[val] = 1;

  if (m.find(val - 1) != m.end()) {
    return m[val] = 1 + find_len(m, val - 1);
  }

  return m[val];
}

// INFO: Really slower than others, Optimize the algorithm
int longest_consecutive(vector<int> &nums) {
  unordered_map<int, int> m;

  for (int val : nums)
    m[val] = 0;

  int res = 0;
  for (pair<int, int> p : m) {
    int val = p.first;

    int len = find_len(m, val);
    res = max(res, len);
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

    int res = longest_consecutive(nums);
    cout << res << '\n';
  }

  return 0;
}
