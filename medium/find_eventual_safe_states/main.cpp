#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> &graph, vector<bool> &stack,
         vector<bool> &safe_nodes, int index) {

  if (stack[index])
    return false;

  stack[index] = 1;

  for (int i = 0; i < graph[index].size(); i++) {
    int v = graph[index][i];

    if (safe_nodes[v])
      continue;

    if (!dfs(graph, stack, safe_nodes, v))
      return false;
  }

  stack[index] = 0;
  safe_nodes[index] = 1;

  return true;
}

vector<int> eventual_safe_nodes(vector<vector<int>> &graph) {
  int m = graph.size();

  vector<bool> safe_nodes(m, 0);
  for (int i = 0; i < m; i++)
    if (graph[i].size() == 0)
      safe_nodes[i] = 1;

  for (int i = 0; i < m; i++) {
    if (!safe_nodes[i]) {
      vector<bool> stack(m, 0);
      if (dfs(graph, stack, safe_nodes, i))
        safe_nodes[i] = 1;
    }
  }

  vector<int> result;
  for (int i = 0; i < m; i++)
    if (safe_nodes[i])
      result.push_back(i);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m;
    cin >> m;

    vector<vector<int>> graph;
    for (int i = 0; i < m; i++) {
      int n;
      cin >> n;

      vector<int> edges(n, 0);
      for (int j = 0; j < n; j++)
        cin >> edges[j];

      graph.push_back(edges);
    }

    vector<int> result = eventual_safe_nodes(graph);

    for (int val : result)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
