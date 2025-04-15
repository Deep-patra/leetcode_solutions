#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int magnificent_sets(int n, vector<vector<int>> &edges) {
  vector<vector<int>> adj(n, vector<int>(0));
  for (int i = 0; i < edges.size(); i++) {
    int first = edges[i][0] - 1, second = edges[i][1] - 1;

    adj[first].push_back(second);
    adj[second].push_back(first);
  }

  vector<int> parent(n, -1);

  int max_groups = -1;
  for (int i = 0; i < n; i++) {
    queue<pair<int, int>> q; // vertex and the current group
    vector<int> groups(n, -1);

    groups = vector<int>(n, -1);

    q.push({i, 1});
    groups[i] = 1;

    int not_possible = 0;
    while (!q.empty() && !not_possible) {
      pair<int, int> front = q.front();
      q.pop();

      for (int v : adj[front.first]) {

        // if the current node in the parent
        // skip this nodej
        if (parent[front.first] == v)
          continue;

        if (groups[v] != -1 && abs(groups[v] - groups[front.first]) != 1) {
          not_possible = 1;
          break;
        }

        q.push({v, front.second + 1});
        groups[v] = front.second + 1;
        parent[v] = front.first;
      }
    }

    cout << "For Index => " << i << endl;
    for (int j = 0; j < groups.size(); j++)
      cout << groups[j] << " ";

    cout << (not_possible ? "Not Possible" : "Possible") << endl;
    cout << '\n' << "***************" << '\n';

    if (!not_possible) {
      for (int j = 0; j < groups.size(); j++)
        max_groups = max(groups[j], max_groups);
    }
  }

  return max_groups;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> edges(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++)
      cin >> edges[i][0] >> edges[i][1];

    int result = magnificent_sets(n, edges);
    cout << result << '\n';
  }

  return 0;
}
