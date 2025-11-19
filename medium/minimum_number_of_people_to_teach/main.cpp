#include <bits/stdc++.h>
using namespace std;

// Can be solved with dfs or bfs
int minimum_teachings(int n, vector<vector<int>> &languages,
                      vector<vector<int>> &friendships) {

  vector<vector<int>> adj(n + 1);
  vector<vector<bool>> l(n + 1, vector<bool>(n + 1, 0));

  for (vector<int> edge : friendships)
    adj[edge[0]].push_back(edge[1]);

  for (int i = 0; i < languages.size(); i++) {
    for (vector<int> u : languages[i])
      l[u][i] = 1;
  }

  int res = 0;

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> languages(n), friendships(m, vector<int>(2));

    for (int i = 0; i < n; i++) {
      int l;
      cin >> l;

      vector<int> temp(l);
      for (int j = 0; j < l; j++)
        cin >> temp[j];

      languages[i] = temp;
    }

    for (int i = 0; i < m; i++)
      cin >> friendships[i][0] >> friendships[i][1];

    int res = minimum_teachings(n, languages, friendships);
    cout << res << endl;
  }

  return 0;
}
