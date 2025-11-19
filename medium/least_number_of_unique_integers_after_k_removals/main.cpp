#include <bits/stdc++.h>
using namespace std;

int freq[100001];

int find_least_num_of_unique_ints(vector<int> &arr, int k) {
  int n = arr.size();

  unordered_map<int, int> m;
  for (int val : arr)
    m[val]++;

  memset(freq, 0, sizeof(freq));

  int res = m.size(), max_freq = 0, min_freq = 1e5;
  while (m.size() > 0) {
    auto it = m.begin();
    freq[it->second]++;

    max_freq = max(max_freq, it->second);
    min_freq = min(min_freq, it->second);

    m.erase(it);
  }

  for (int i = min_freq; k > 0 && i <= max_freq; i++) {
    while (freq[i] > 0 && k > 0) {
      k -= i;

      if (k >= 0) {
        freq[i]--;
        res--;
      }
    }
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

    int res = find_least_num_of_unique_ints(nums, k);
    cout << res << endl;
  }

  return 0;
}
