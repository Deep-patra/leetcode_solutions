#include <bits/stdc++.h>  
using namespace std;

int max_distinct_elements(vector<int> &nums, int k) {
  int n = nums.size();

  unordered_map<int, int> m;
  for (int val : nums)
    m[val]++;

  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  long long res = 0, prev = (nums[0] - k) - 1;
  for (int val : nums) {
     
    int freq = m[val];
    prev = max(prev, 1LL * (val - k - 1));

    int diff = (val + k) - prev;

    if (freq >= diff) {

      res += diff;
      prev = val + k;

    } else {

      res += freq;
      prev += freq;

    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int res = max_distinct_elements(nums, k);
    cout << res << endl;
  }

  return 0;
}
