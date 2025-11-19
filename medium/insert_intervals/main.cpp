#include <bits/stdc++.h>
using namespace std;

int find_index(vector<vector<int>> &intervals, int val) {

  int l = 0, r = intervals.size() - 1, mid, pos = -1;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (intervals[mid][0] <= val && val <= intervals[mid][1])
      return mid;

    if (intervals[mid][1] < val) {
      pos = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return pos;
}

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  int n = intervals.size();
  vector<vector<int>> res;

  if (n == 0) {
    res.push_back(newInterval);
    return res;
  }

  int l = find_index(intervals, newInterval[0]);
  int r = find_index(intervals, newInterval[1]);

  for (int i = 0; i < l; i++)
    res.push_back(intervals[i]);

  if (l != -1) {
    if (intervals[l][1] < newInterval[0])
      res.push_back(intervals[l]);

    if (intervals[l][0] < newInterval[0] && intervals[l][1] >= newInterval[0])
      newInterval[0] = intervals[l][0];
  }

  if (r != -1) {
    if (intervals[r][1] > newInterval[1])
      newInterval[1] = intervals[r][1];
  }

  res.push_back(newInterval);

  for (int i = r + 1; i < n; i++)
    res.push_back(intervals[i]);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    vector<int> newInterval(2, 0);
    cin >> n >> newInterval[0] >> newInterval[1];

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
      cin >> intervals[i][0] >> intervals[i][1];

    vector<vector<int>> res = insert(intervals, newInterval);

    for (vector<int> v : res) {
      for (int val : v)
        cout << val << " ";

      cout << endl;
    }
  }

  return 0;
}
