#include <bits/stdc++.h>
using namespace std;

bool is_zero_array(vector<int> &nums, vector<vector<int>> &queries) {
  int n = nums.size();

  vector<long> diff(n, 0);

  for (int i = 0; i < queries.size(); i++) {
    diff[queries[i][0]]++;

    if (queries[i][1] < n - 1)
      diff[queries[i][1] + 1]--;
  }

  // for (int i = 0; i < n; i ++)
  //   cout << diff[i] << " ";
  // cout << endl;

  int d = 0;
  for (int i = 0; i < n; i++) {
    d -= diff[i];

    nums[i] = max(nums[i] + d, 0);

    if (nums[i] > 0)
      return 0;
  }

  return 1;
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

    vector<vector<int>> queries(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++)
      cin >> queries[i][0] >> queries[i][1];

    bool res = is_zero_array(nums, queries);
    cout << res << '\n';
  }

  return 0;
}
