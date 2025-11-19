#include <bits/stdc++.h>
using namespace std;

// INFO : very slow, needs a better solution, maybe instead of DFS, BFS could work? 
void dfs(vector<vector<pair<int, int>>> &adj, vector<int> &time_to_reach, int i,
         int curr = 0) {

  if (time_to_reach[i] < curr) return

  time_to_reach[i] = min(time_to_reach[i], curr);

  for (pair<int, int> &p : adj[i])
    dfs(adj, time_to_reach, p.first, curr + p.second);
}

int network_delay_time(vector<vector<int>> &times, int n, int k) {

  vector<vector<pair<int, int>>> adj(n + 1);

  for (const auto &t : times)
    adj[t[0]].push_back({t[1], t[2]});

  vector<int> time_to_reach(n + 1, INT_MAX);
  dfs(adj, time_to_reach, k);

  int max_time = time_to_reach[0] = -1;
  for (int &t : time_to_reach) {
    if (t == INT_MAX)
      return -1;

    max_time = max(max_time, t);
  }

  return max_time;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> times(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++)
      cin >> times[i][0] >> times[i][1] >> times[i][2];

    int res = network_delay_time(times, n, k);
    cout << res << '\n';
  }

  return 0;
}
