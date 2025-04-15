#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int get_interval(vector<pair<vector<int>, int>> &intervals_with_index,
                 int curr) {

  int n = intervals_with_index.size();
  int low = curr, high = n - 1, mid,
      target = intervals_with_index[curr].first[1];

  if (intervals_with_index[curr].first[0] ==
      intervals_with_index[curr].first[1])
    return curr;

  while (low <= high) {
    mid = low + (high - low) / 2;

    int val = intervals_with_index[mid].first[0];

    if (val == target)
      break;

    if (mid < n - 1 && intervals_with_index[mid - 1].first[0] < target &&
        intervals_with_index[mid].first[0] > target)
      break;

    else if (val < target)
      low = mid + 1;

    else
      high = mid - 1;
  }

  if (intervals_with_index[mid].first[0] < target)
    return -1;

  return intervals_with_index[mid].second;
}

vector<int> find_right_intervals(vector<vector<int>> &intervals) {

  vector<pair<vector<int>, int>> intervals_with_index(intervals.size());

  for (int i = 0; i < intervals.size(); i++)
    intervals_with_index[i] = make_pair(intervals[i], i);

  auto comparator = [=](pair<vector<int>, int> a,
                        pair<vector<int>, int> b) -> bool {
    return a.first[0] < b.first[0];
  };

  sort(intervals_with_index.begin(), intervals_with_index.end(), comparator);

  // for (auto item : intervals_with_index)
  //   cout << "(" << item.first[0] << ", " << item.first[1] << ")" << endl;

  vector<int> result(intervals.size(), -1);

  for (int i = 0; i < intervals.size() - 1; i++) {
    int pos = get_interval(intervals_with_index, i);

    if (pos != -1)
      result[intervals_with_index[i].second] = pos;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
      cin >> intervals[i][0] >> intervals[i][1];

    vector<int> result = find_right_intervals(intervals);

    for (int val : result)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
