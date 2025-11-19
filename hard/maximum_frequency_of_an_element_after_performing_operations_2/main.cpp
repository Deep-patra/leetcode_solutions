#include <bits/stdc++.h>
using namespace std;

int max_frequency(vector<int> &nums, int k, int numOperations) {
  int n = nums.size(), max_freq = 0;

  unordered_map<int, int> m;

  vector<pair<int, int>> values;

  for (int val : nums) {

    m[val]++;

    max_freq = max(max_freq, m[val]);

    values.push_back({max(val - k, 0), 1});
    values.push_back({ val, 0 });
    values.push_back({val + k, -1});
  }

  auto cmp = [](pair<int, int> &a, pair<int, int> &b) -> int {
    if (a.first == b.first)
      return a.second > b.second;

    return a.first < b.first;
  };

  sort(values.begin(), values.end(), cmp);

  int s = values.size();
  for (int i = 0, curr = 0; i < s; i++) {

    curr += values[i].second;

    int f = 0;
    if (m.count(values[i].first))
      f = m[values[i].first];

    int t = min(numOperations, curr - f);

    max_freq = max(max_freq, t + f);
  }

  return max_freq;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k, num_operations;
    cin >> n >> k >> num_operations;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int freq = max_frequency(nums, k, num_operations);
    cout << freq << endl;
  }

  return 0;
}
