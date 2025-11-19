#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> range_add_queries(int n, vector<vector<int>> &queries) {

  int m = queries.size();

  vector<vector<int>> diff(n, vector<int>(n, 0));

  for (int i = 0; i < m; i++) {

    vector<int> q = queries[i];

    diff[q[0]][q[1]] += 1;

    if (q[3] + 1 < n)
      diff[q[0]][q[3] + 1] += -1;

    if (q[2] + 1 < n)
      diff[q[2] + 1][q[1]] += -1;

    if (q[2] + 1 < n && q[3] + 1 < n)
      diff[q[2] + 1][q[3] + 1] += 1;
  }

  vector<int> prev_diff(n, 0);
  for (int i = 0; i < n; i++) {

    int d = 0;

    for (int j = 0; j < n; j++) {

      d += diff[i][j];

      int curr_diff = prev_diff[j] + d;

      diff[i][j] = curr_diff;

      prev_diff[j] = curr_diff;
    }
  }

  return diff;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> queries(m, vector<int>(4, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 4; j++)
        cin >> queries[i][j];
    }

    vector<vector<int>> res = range_add_queries(n, queries);

    for (vector<int> r : res) {
      for (int val : r)
        cout << val << " ";

      cout << endl;
    }
  }

  return 0;
}
