#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// INFO: Solved but a bit slow
// TODO: Write a better faster solution (It's a bit slow)
ll max_taxi_earnings(int n, vector<vector<int>> &rides) {
  vector<ll> earnings(n + 1, 0);

  auto comparator = [](vector<int> &a, vector<int> &b) -> bool {
    if (a[0] == b[0])
      return a[1] < b[1];

    return a[0] < b[0];
  };

  sort(rides.begin(), rides.end(), comparator);

  auto cmp = [&](int a, int b) { return rides[a][1] > rides[b][1]; };

  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

  for (int i = 1, j = 0; i <= n; i++) {

    // push the rides which have the starting time less than
    // or equal to the current time
    while (j < rides.size() && rides[j][0] <= i)
      pq.push(j++);

    // pop the rides whose end time have passed
    while (!pq.empty()) {
      int t = pq.top();

      if (i < rides[t][1])
        break;

      ll p = (rides[t][1] - rides[t][0]) + rides[t][2];
      earnings[i] = max(earnings[i], 1LL * earnings[rides[t][0]] + p);

      pq.pop();
    }

    earnings[i] = max(earnings[i], earnings[i - 1]);
  }

  return earnings[n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> rides(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++)
      cin >> rides[i][0] >> rides[i][1] >> rides[i][2];

    ll res = max_taxi_earnings(n, rides);
    cout << res << '\n';
  }

  return 0;
}
