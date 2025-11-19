#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parents, int i) {

  if (parents[i] != i)
    return parents[i] = find(parents, parents[i]);

  return parents[i];
}

void ds_union(vector<int> &parents, int i, int j) {
  int f = find(parents, i), s = find(parents, j);

  if (f < s)
    parents[s] = f;
  else
    parents[f] = s;
}

vector<int> find_redundant_connection(vector<vector<int>> &edges) {

  vector<int> parents(edges.size(), -1);

  for (int i = 0; i < edges.size(); i++)
    parents[i] = i;

  for (auto &edge : edges) {

    if (find(parents, edge[0] - 1) == find(parents, edge[1] - 1))
      return edge;

    ds_union(parents, edge[0] - 1, edge[1] - 1);
  }

  return edges.back();
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++)
      cin >> edges[i][0] >> edges[i][1];

    vector<int> result = find_redundant_connection(edges);
    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
