#include <bits/stdc++.h>
using namespace std;

vector<int> find_order(int num_courses, vector<vector<int>> &prerequisites) {
  vector<vector<int>> adj(num_courses);

  for (auto &v : prerequisites)
    adj[v[1]].push_back(v[0]);

  vector<int> res, ind(num_courses, 0); // In-degree of every vertex
  res.reserve(num_courses);

  queue<int> q;

  for (int i = 0; i < num_courses; i++) {
    for (int v : adj[i])
      ind[v]++;
  }

  for (int i = 0; i < num_courses; i++)
    if (ind[i] == 0)
      q.push(i);

  while (!q.empty()) {

    int front = q.front();
    q.pop();

    for (int v : adj[front]) {
      ind[v]--;

      if (ind[v] == 0)
        q.push(v);
    }

    res.push_back(front);
  }

  return res.size() >= num_courses ? res : vector<int>(0);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (int i = 0; i < m; i++)
      cin >> prerequisites[i][0] >> prerequisites[i][1];

    vector<int> order = find_order(n, prerequisites);

    for (int v : order)
      cout << v << " ";

    cout << endl;
  }

  return 0;
}
