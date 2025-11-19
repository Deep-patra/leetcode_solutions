#include <bits/stdc++.h>  
using namespace std;

int maximal_network_rank(int n, vector<vector<int>> &roads) {

  typedef pair<int, int> pii;

  vector<pii> sz(n);

  for (int i = 0; i < n; i ++)
    sz[i] = make_pair(0, i);

  vector<vector<int>> adj(n, vector<int>(n, 0));

  for (auto &r : roads) {
    adj[r[0]][r[1]] = 1;
    adj[r[1]][r[0]] = 1;

    sz[r[0]].first ++;
    sz[r[1]].first ++;
  }
 
  auto comparator = [&](pii &a, pii &b) -> bool {
    return a.first < b.first;
  };

  sort(sz.begin(), sz.end());

  int res = 0;
  for (int i = 0; i < n - 1; i ++) {
    for (int j = i + 1; j < n; j ++) {
      
      int m = sz[i].first + sz[j].first;

      if (adj[sz[i].second][sz[j].second])
        m --;

      res = max(m, res);
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> roads(m, vector<int>(2));
    for (int i = 0; i < m; i ++)
      cin >> roads[i][0] >> roads[i][1];

    int max_rank = maximal_network_rank(n, roads);
    cout << max_rank << endl;
  }

  return 0;
}
