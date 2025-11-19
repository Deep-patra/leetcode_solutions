#include <bits/stdc++.h>
using namespace std;

bool is_possible_divide(vector<int> &nums, int k) {
  int n = nums.size();

  if (n % k != 0)
    return 0;

  map<int, int> freq;

  for (int val : nums)
    freq[val]++;

  while (freq.size() > 0) {

    auto it = freq.begin();

    int v = it->first;

    freq[v]--;

    if (freq[v] == 0)
      freq.erase(v);

    int start = v;
    for (int i = 1; i < k; i++) {
      if (!freq.count(start + 1))
        return 0;

      freq[start + 1]--;

      if (freq[start + 1] == 0)
        freq.erase(start + 1);

      start++;
    }
  }

  return 1;
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

    bool res = is_possible_divide(nums, k);
    cout << res << endl;
  }

  return 0;
}
