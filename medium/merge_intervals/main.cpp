#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  int n = intervals.size();

  auto cmp = [](vector<int> &a, vector<int> &b) -> bool {
    if (a[0] == b[0])
      return a[1] < b[1];

    return a[0] < b[0];
  };

  sort(intervals.begin(), intervals.end(), cmp);

  vector<vector<int>> res;

  pair<int, int> curr = make_pair(intervals[0][0], intervals[0][1]);
  for (int i = 1; i < n; i ++) {
    if (intervals[i][0] <= curr.second) {
      curr = make_pair(curr.first, max(curr.second, intervals[i][1]));
      continue;
    }

    res.push_back({ curr.first, curr.second });
    curr = make_pair(intervals[i][0], intervals[i][1]);
  }

  res.push_back({ curr.first, curr.second });

  return res;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
      cin >> intervals[i][0] >> intervals[i][1];

    vector<vector<int>> result = merge(intervals);

    for (vector<int> list : result) {
      for (int val : list)
        cout << val << " ";

      cout << '\n';
    }
  }

  return 0;
}
