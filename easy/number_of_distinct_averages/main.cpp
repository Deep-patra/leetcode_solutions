#include <bits/stdc++.h>
using namespace std;

int find_min(int freq[]) {
  for (int i = 0; i < 101; i++)
    if (freq[i] > 0) {
      freq[i]--;
      return i;
    }

  return -1;
}

int find_max(int freq[]) {

  for (int i = 100; i >= 0; i--) {
    if (freq[i] > 0) {
      freq[i]--;
      return i;
    }
  }

  return -1;
}

int distinct_averages(vector<int> &nums) {
  int n = nums.size();

  int freq[101];
  memset(freq, 0, sizeof(freq));

  for (int val : nums)
    freq[val]++;

  int min_val = find_min(freq), max_val = find_max(freq);

  unordered_set<int> s;

  while (max(max_val, min_val) != -1) {
    if (min(max_val, min_val) == -1)
      max_val = min_val = max(max_val, min_val);

    s.insert(max_val + min_val);

    max_val = find_max(freq);
    min_val = find_min(freq);
  }

  return s.size();
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

    int res = distinct_averages(nums);
    cout << res << '\n';
  }

  return 0;
}
