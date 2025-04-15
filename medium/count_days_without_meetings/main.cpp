#include <bits/stdc++.h>
using namespace std;

int count_days(int days, vector<vector<int>> &meetings) {

  auto comparator = [](vector<int> &a, vector<int> &b) -> bool {
    if (a[0] == b[0])
      return a[1] < b[1];

    return a[0] < b[0];
  };

  sort(meetings.begin(), meetings.end(), comparator);

  int latest_end = 0, free_days = 0;
  for (vector<int> m : meetings) {
    if (latest_end < m[0]) {
      free_days += m[0] - latest_end - 1;
    }

    latest_end = max(latest_end, m[1]);
  }

  free_days += days - latest_end;

  return free_days;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int days, m;
    cin >> days >> m;

    vector<vector<int>> meetings(m, vector<int>(2));
    for (int i = 0; i < m; i++)
      cin >> meetings[i][0] >> meetings[i][1];

    int result = count_days(days, meetings);
    cout << result << '\n';
  }

  return 0;
}
