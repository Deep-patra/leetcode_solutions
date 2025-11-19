#include <bits/stdc++.h>  
using namespace std;

void dfs(vector<vector<int>> &rooms, vector<int> &visited, int i) {

  visited[i] = 1;

  for (auto &keys : rooms[i]) {
    for (int key : keys) {
      if (!visited[key]) 
        dfs(rooms, visited, key);
    }
  }
}

bool can_visit_all_rooms(vector<vector<int>> &rooms) {
  int n = rooms.size();

  vector<bool> visited(n, 0);

  dfs(rooms, visited, 0);

  for (int i = 0; i < n; i ++)
    if (!visited) return 0;

  return 1;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<vector<int>> rooms(n);
    for (int i = 0; i < n; i ++) {
      int m;
      cin >> m;

      for (int j = 0; j < m; j ++) {
        int v;
        cin >> v;

        rooms[i].push_back(v);
      }
    }

    bool res = can_visit_all_rooms(rooms);
    cout << res << '\n';
  }

  return 0;
}
