#include <bits/stdc++.h>
using namespace std;

// TODO: Complete the Implementation
int max_events(vector<vector<int>> &events) {
  int n = events.size();

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> events(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
      cin >> events[i][0] >> events[i][1];

    int res = max_events(events);
    cout << res << '\n';
  }

  return 0;
}
