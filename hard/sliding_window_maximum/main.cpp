#include <bits/stdc++.h>
using namespace std;

vector<int> maximum_sliding_window(vector<int> &nums, int k) {
  map<int, int> m;
  vector<int> result;

  m[nums[0]]++;

  int l = 0, r = 0;
  while (l <= r) {
    if ((r - l + 1) < k) {
      r++;

      m[nums[r]]++;

    } else {

      // add the maximum value in the result array
      auto maximum = m.rbegin();
      result.push_back(maximum->first);

      if (r == nums.size() - 1)
        break;

      m[nums[l++]]--;
      if (m[nums[l - 1]] == 0)
        m.erase(nums[l - 1]);

      m[nums[++r]]++;
    }
  }

  return result;
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

    vector<int> result = maximum_sliding_window(nums, k);
    for (int val : result)
      cout << val << ' ';

    cout << '\n';
  }

  return 0;
}
