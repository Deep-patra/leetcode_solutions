#include <bits/stdc++.h>
using namespace std;

// INFO: Solved but a bit slower than the rest of the solutions
// TODO: Write a more efficient implemenation 
int most_booked(int n, vector<vector<int>> &meetings) {
  int l = meetings.size();

  typedef long long ll;

  vector<int> rooms(n, 0);

  sort(meetings.begin(), meetings.end(),
       [](vector<int> &a, vector<int> &b) -> bool {
         if (a[0] == b[0])
           return a[1] < b[1];

         return a[0] < b[0];
       });

  auto cmp = [](pair<ll, int> &a, pair<ll, int> &b) -> bool {
    if (a.first == b.first)
      return a.second > b.second;

    return a.first > b.first;
  };

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(cmp)> pq(cmp);

  pq.push({0, 0});

  for (int i = 0; i < l; i++) {

    if (pq.top().first <= meetings[i][0]) {
      stack<int> s;

      while (!pq.empty() && pq.top().first <= meetings[i][0]) {
        s.push(pq.top().second);
        pq.pop();
      }

      while (!s.empty()) {
        int t = s.top();
        s.pop();

        pq.push({0, t});
      }
    }

    if (pq.size() < n) {

      if (pq.top().first <= meetings[i][0]) {
        pair<int, int> p = pq.top();
        pq.pop();

        rooms[p.second]++;

        pq.push({meetings[i][1], p.second});

      } else {
        for (int j = 0; j < n; j++)
          if (rooms[j] == 0) {
            pq.push({meetings[i][1], j});
            rooms[j]++;
            break;
          }
      }

    } else {

      if (pq.top().first <= meetings[i][0]) {

        pair<int, int> p = pq.top();
        pq.pop();

        rooms[p.second]++;

        pq.push({meetings[i][1], p.second});

      } else {

        pair<int, int> p = pq.top();
        pq.pop();

        rooms[p.second]++;

        pq.push({1LL * meetings[i][1] + (p.first - meetings[i][0]), p.second});
      }
    }
  }

  int max = 0, room;
  for (int i = 0; i < n; i++) {
    if (max < rooms[i]) {
      max = rooms[i];
      room = i;
    }
  }

  return room;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> meetings(m, vector<int>(2));
    for (int i = 0; i < m; i++)
      cin >> meetings[i][0] >> meetings[i][1];

    int res = most_booked(n, meetings);
    cout << res << endl;
  }

  return 0;
}
