#include <bits/stdc++.h>
using namespace std;

bool is_cyclic(int node, vector<vector<int>> &adj, vector<bool> &visited) {

  if (visited[node])
    return 1;

  visited[node] = 1;

  for (int v : adj[node]) {
    if (is_cyclic(v, adj, visited))
      return 1;
  }

  visited[node] = 0;

  return false;
}

// INFO: Getting TLE
int find_valid_path(int i, const string &colors, vector<vector<int>> &color_map,
                    vector<bool> &visited, const vector<vector<int>> &adj) {

  if (visited[i]) {
    int max_value = 1;

    for (int c = 0; c < 26; c++)
      max_value = max(max_value, color_map[i][c]);

    return max_value;
  }

  visited[i] = 1;

  int max_value = 1;
  for (int v : adj[i]) {
    find_valid_path(v, colors, color_map, visited, adj);

    for (int j = 0; j < 26; j ++)
      color_map[i][j] = max(color_map[i][j], color_map[v][j]);
  }

  color_map[i][colors[i] - 'a']++;

  for (int c = 0; c < 26; c++)
    max_value = max(max_value, color_map[i][c]);

  return max_value;
}

int largest_path_value(string &colors, vector<vector<int>> &edges) {
  vector<vector<int>> adj(colors.size(), vector<int>(0));

  for (int i = 0; i < edges.size(); i++)
    adj[edges[i][0]].push_back(edges[i][1]);

  vector<bool> visited(colors.size() + 1, 0);

  // Check if the graph is Cyclic
  for (int i = 0; i < colors.size(); i++) {

    if (is_cyclic(i, adj, visited)) {
      return -1;
    }
  }

  vector<vector<int>> color_map(colors.size() + 1, vector<int>(26, 0));

  int max_value = 0;
  for (int i = 0; i < colors.size(); i++) 
    max_value = max(max_value,
                    find_valid_path(i, colors, color_map, visited, adj));


  return max_value;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string colors;
    cin >> colors;

    int m;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++)
      cin >> edges[i][0] >> edges[i][1];

    int res = largest_path_value(colors, edges);
    cout << res << '\n';
  }

  return 0;
}
