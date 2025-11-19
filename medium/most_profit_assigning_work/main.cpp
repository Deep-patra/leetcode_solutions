#include <bits/stdc++.h>
using namespace std;

int max_profit_assignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {

  vector<pair<int, int>> diff_idx;
  diff_idx.reserve(difficulty.size());

  for (int i = 0, n = difficulty.size(); i < n; i++)
    diff_idx.push_back({difficulty[i], i});

  sort(diff_idx.begin(), diff_idx.end());

  vector<int> max_profit(profit.size());
  for (int i = 0, n = difficulty.size(), max_p = INT_MIN; i < n; i++) {
    int idx = diff_idx[i].second;

    max_p = max(max_p, profit[idx]);

    max_profit[i] = max_p;
  }

  auto bs = [&](int w) -> int {
    int l = 0, h = diff_idx.size() - 1, pos = -1;

    while (l <= h) {
      int mid = l + (h - l) / 2;

      if (diff_idx[mid].first <= w) {
        l = mid + 1;
        pos = mid;
      }

      else
        h = mid - 1;
    }

    if (pos == -1)
      return 0;

    return max_profit[pos];
  };

  int res = 0;
  for (int i = 0, n = worker.size(); i < n; i++)
    res += bs(worker[i]);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> difficulty(n), profit(n);
    for (int i = 0; i < n; i++)
      cin >> difficulty[i];

    for (int i = 0; i < n; i++)
      cin >> profit[i];

    int m;
    cin >> m;

    vector<int> worker(m);
    for (int i = 0; i < m; i++)
      cin >> worker[i];

    int res = max_profit_assignment(difficulty, profit, worker);
    cout << res << endl;
  }

  return 0;
}
