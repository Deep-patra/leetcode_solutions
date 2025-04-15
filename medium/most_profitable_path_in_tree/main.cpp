#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &parent, vector<bool> &visited, int target, int curr) {

  visited[curr] = 1;

  for (int v : adj[curr]) {
    if (visited[v])
     continue;

    parent[v] = curr;

    if (v == target)
      return;

    dfs(adj, parent, visited, target, v);
  }

  return;
}

int find_profitable_path(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &amount, int u = 0) {
  visited[u] = 1;

  cout << "node => " << u << " amount => " << amount[u]  << endl;

  int sum = INT_MIN;
  for (int v : adj[u]) {
    if (visited[v]) continue;

    sum = max(sum, find_profitable_path(adj, visited, amount, v));
  }  

  return sum == INT_MIN ? amount[u] : sum + amount[u];
}

int most_profitable_path(vector<vector<int>> &edges, int bob,
                         vector<int> &amount) {

  vector<vector<int>> adj(amount.size(), vector<int>(0));

  for (int i = 0; i < edges.size(); i++) {
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }

  vector<int> parent(amount.size(), -1);
  vector<bool> visited(amount.size(), 0);

  dfs(adj, parent, visited, bob, 0);


  // find the number of nodes between bob and 0
  int nodes = 0;
  for (int i = bob; i != -1; i = parent[i])
    nodes ++;

  int half = nodes >> 1;
  int curr = bob;

  while (curr != -1 && half >= 0) {
    if (half == 0 && nodes & 1)
      amount[curr] >>= 1;

    else if (half > 0)
      amount[curr] = 0;

    curr = parent[curr];
    half --;
  }

  // cout << "amount => " << endl;
  // for (int val : amount)
  //   cout << val << " ";
  // cout << endl;

  visited = vector<bool>(visited.size(), 0);

  return find_profitable_path(adj, visited, amount, 0);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, bob;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
      cin >> edges[i][0] >> edges[i][1];

    cin >> bob;

    int m;
    cin >> m;

    vector<int> amount(m, 0);
    for (int i = 0; i < m; i++)
      cin >> amount[i];

    int result = most_profitable_path(edges, bob, amount);
    cout << result << endl;
  }

  return 0;
}
