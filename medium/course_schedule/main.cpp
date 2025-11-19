#include <bits/stdc++.h>
using namespace std;

bool can_finish(int num_courses, vector<vector<int>> &prerequisites) {
  vector<vector<int>> adj(num_courses);

  for (auto &v : prerequisites) 
    adj[v[1]].push_back(v[0]);

  vector<int> ind(num_courses, 0);
  vector<bool> visited(num_courses, 0);

  queue<int> q;

  for (int i = 0; i < num_courses; i ++) {
    for (int a : adj[i]) {
      ind[a] ++;
    }
  }

  for (int i = 0; i < num_courses; i ++)
    if (ind[i] == 0)
      q.push(i);
  

  int curr = 0;
  while (!q.empty()) {
   
    int front = q.front();
    q.pop();

    visited[front] = 1;

    for (int a : adj[front]) {
      ind[a] --;

      if (ind[a] == 0 && !visited[a]) q.push(a);
    } 

    curr ++;
  }

  return curr >= num_courses;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> prerequisities(m, vector<int>(2));
    for (int i = 0; i < m; i ++)
      cin >> prerequisities[i][0] >> prerequisities[i][1];

    bool res = can_finish(n, prerequisities);
    cout << res << '\n';

  }

  return 0;
}
