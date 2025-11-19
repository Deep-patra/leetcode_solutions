#include <bits/stdc++.h>
using namespace std;

// TODO: Complete the Implementation
// INFO: USE Greedy and priority queue implementation
int max_removal(vector<int> &nums, vector<vector<int>> &queries) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    cin >> m;

    vector<int> queries(m, vector<int>(2, 0));
    for (int i = 0; i < m; i ++)
      cin >> queries[i][0] >> queries[i][1];

    int res = max_removal(nums, queries);
    cout << res << '\n';
  }

  return 0;
}
