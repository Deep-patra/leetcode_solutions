#include <bits/stdc++.h>
using namespace std;

// Using line Sweep Approach
int min_zero_array(vector<int> &nums, vector<vector<int>> &queries) {
  vector<int> diff(nums.size() + 1, 0);

  int sum = 0, k = 0, index = 0;
  for (int i = 0; i < nums.size(); i++) {

    while (sum + diff[i] < nums[i]) {

      if (index >= queries.size())
        return -1;

      int l = queries[index][0], r = queries[index][1], val = queries[index][2];

      if (r >= i) {
        diff[max(l, i)] += val;
        diff[r + 1] -= val;
      }

      index++;
      k++;
    }

    sum += diff[i];
  }

  return k;
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

    int m;
    cin >> m;

    vector<vector<int>> queries(m, vector<int>(3));
    for (int i = 0; i < m; i++)
      cin >> queries[i][0] >> queries[i][1] >> queries[i][2];

    int result = min_zero_array(nums, queries);
    cout << result << '\n';
  }

  return 0;
}
