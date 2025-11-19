#include <bits/stdc++.h>
using namespace std;

int erase_overlap_intervals(vector<vector<int>> &intervals) {
  int n = intervals.size();

  auto cmp = [](vector<int> &a, vector<int> &b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
  };

  sort(intervals.begin(), intervals.end(), cmp);

  int res = 0;
  for (int i = 0; i < n; i++) {
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
      cin >> intervals[i][0] >> intervals[i][1];

    int res = erase_overlap_intervals(intervals);
    cout << res << endl;
  }

  return 0;
}
