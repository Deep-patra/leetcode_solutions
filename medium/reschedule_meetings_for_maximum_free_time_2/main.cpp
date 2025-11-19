#include <bits/stdc++.h>
using namespace std;

// INFO: Solved, But the Rumtime is around 53ms, needs a runtime of 4 ms
// TODO: Implement a more efficient algorithm
int max_free_time(int eventTime, vector<int> &startTime, vector<int> &endTime) {
  int n = startTime.size(), res = 0;

  typedef pair<int, int> pi;

  auto cmp = [](const pi &a, const pi &b) -> bool {
    if (a.first == b.first)
      return a.second < b.second;

    return a.first < b.first;
  };

  vector<pi> free_times;

  auto find_free_time = [&](int t, int left, int right) -> bool {
    int l = 0, r = free_times.size() - 1, mid, pos = -1;

    while (l <= r) {
      mid = l + (r - l) / 2;

      if (free_times[mid].first >= t) {
        r = mid - 1;
        pos = mid;
      } else
        l = mid + 1;
    }

    if (pos == -1)
      return 0;

    for (int i = pos; i < free_times.size(); i++) {
      if (free_times[i].second != left && free_times[i].second != right)
        return 1;
    }

    return 0;
  };

  // store the free times in a set
  for (int i = 0; i <= n; i++) {
    int l = i == 0 ? 0 : endTime[i - 1];
    int r = i == n ? eventTime : startTime[i];

    if (r - l == 0)
      continue;

    free_times.push_back({r - l, l});
  }

  sort(free_times.begin(), free_times.end(), cmp);

  for (int i = 0; i < n; i++) {
    int l = i == 0 ? 0 : endTime[i - 1];
    int r = i == n - 1 ? eventTime : startTime[i + 1];

    int t = endTime[i] - startTime[i];

    // check if a free time exists, except the adjacent free time
    if (find_free_time(t, l, endTime[i]))
      res = max(res, r - l);
    else
      res = max(res, r - l - t);
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int event_time, n;
    cin >> n >> event_time;

    vector<int> start_time(n), end_time(n);
    for (int i = 0; i < n; i++)
      cin >> start_time[i];

    for (int i = 0; i < n; i++)
      cin >> end_time[i];

    int free_time = max_free_time(event_time, start_time, end_time);
    cout << free_time << endl;
  }

  return 0;
}
