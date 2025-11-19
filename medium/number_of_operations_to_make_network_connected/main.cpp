#include <bits/stdc++.h>  
using namespace std;

int find(vector<int> &parents, int n) {
  if (parents[n] == -1)
    return parents[n] = n;

  else if (parents[n] != n)
    return parents[n] = find(parents, parents[n]);

  return n;
}

void ds_union(vector<int> &parents, int n1, int n2) {
  
  n1 = find(parents, n1);
  n2 = find(parents, n2);

  if (n1 < n2)
    parents[n2] = n1;
  else 
    parents[n1] = n2;
}

int make_connected(int n, vector<vector<int>> &connections) {
  
  int extra_edges = 0;

  vector<int> parents(n, -1);

  for (auto &c : connections) {
    if (find(parents, c[0]) == find(parents, c[1])) {
      extra_edges ++;

      continue;
    }

    ds_union(parents, c[0], c[1]);
  }


  // connected computers
  int c = parents[0] == -1 ? 0 : 1, prev = parents[0];
  for (int p : parents) {
    if (prev != p || p == -1) c ++;
  }

  c --;

  return c > extra_edges ? -1 : c;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> connections(m, vector<int>(2));
    for (int i = 0; i < m; i ++)
      cin >> connections[i][0] >> connections[i][1];

    int res = make_connected(n, connections);
    cout << res << '\n';
  }

  return 0;
}
