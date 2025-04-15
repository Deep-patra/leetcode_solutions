#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// TODO: Complete The Implementation of the Solution

bool dfs(vector<vector<int>> adj, vector<int> &parent, vector<bool> &visited,
         int &cycle_vertex, int u) {
  visited[u] = 1;

  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];

    if (visited[v]) {
      cycle_vertex = v;
      return true;
    }

    parent[v] = u;

    if (dfs(adj, parent, visited, cycle_vertex, v))
      return true;
  }

  return false;
}

vector<int> find_redundant_connection(vector<vector<int>> &edges) {
  vector<vector<int>> adj(edges.size() + 1, vector<int>(0));

  for (int i = 0; i < edges.size(); i++)
    adj[edges[i][0]].push_back(edges[i][1]);

  vector<bool> visited(edges.size() + 1, 0);
  vector<int> parent(edges.size() + 1, -1);

  int cycle_vertex = -1;
  dfs(adj, parent, visited, cycle_vertex, 1);

  visited = vector<bool>(edges.size() + 1, 0);
  for (int i = cycle_vertex; i <= edges.size(); i = parent[i])
    visited[i] = 1;

  vector<int> result;
  for (int i = edges.size() - 1; i >= 0; i--)
    if (visited[edges[i][0]] && visited[edges[i][1]]) {
      result = edges[i];
      break;
    }

  return result;
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
