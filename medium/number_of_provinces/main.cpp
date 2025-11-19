#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &is_connected, vector<int> &parents, int i,
         int j) {

  if (parents[i] == -1)
    parents[i] = j;

  for (int k = 0; k < is_connected.size(); k++) {
    if (is_connected[i][k] && parents[k] == -1)
      dfs(is_connected, parents, k, j);
  }
}

int find_circle_num(vector<vector<int>> &is_connected) {

  int cities = is_connected.size(), res = 0;

  vector<int> parents(cities, -1);

  for (int i = 0; i < cities; i++) {

    if (parents[i] == -1) {
      dfs(is_connected, parents, i, i);
      res++;
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> is_connected(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> is_connected[i][j];

    int res = find_circle_num(is_connected);
    cout << res << '\n';
  }

  return 0;
}
