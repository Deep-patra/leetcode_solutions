#include <bits/stdc++.h>
using namespace std;

// TODO: Complete the Implementation
int max_value(vector<vector<int>> &events, int k) {
  int n = events.size();

  vector<vector<int>> dp(n + 1, vector<int>(k, 0));

  auto comparator = [](vector<int> &a, vector<int> &b) -> bool {
    if (a[0] == b[0])
      return a[1] < b[1];

    return a[0] < b[0];
  };

  sort(events.begin(), events.end(), comparator);

  for (int i = 0; i < n; i ++) 
    dp[i][0] = events[i][2];

  for (int i = 1; i < k; i ++) {

    priority_queue<pair<int, int>> pq;



    for (int j = i; j < n; j ++) {
    
       

    }
  }

  return dp[n - 1][k];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> events(n, vector<int>(3));
    for (int i = 0; i < n; i ++)
      cin >> events[i][0] >> events[i][1] >> events[i][2];

    int res = max_events(events, k);
    cout << res << '\n';
  }

  return 0;
}
