#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &edges, int node, vector<int> &path, int val = 0) {
  if (path[node] != INT_MAX)
    return;

  path[node] = val++;

  if (edges[node] != -1)
    dfs(edges, edges[node], path, val);

  return;
}

int closet_meeting_node(vector<int> &edges, int node1, int node2) {

  int n = edges.size();

  vector<int> mpath1(n, INT_MAX), mpath2(n, INT_MAX);

  dfs(edges, node1, mpath1);
  dfs(edges, node2, mpath2);

  int mpath = INT_MAX, mnode = -1;
  for (int i = 0; i < n; i++) {
    if (mpath > max(mpath1[i], mpath2[i])) {
      mpath = max(mpath1[i], mpath2[i]);
      mnode = i;
    }
  }

  return mnode;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, node1, node2;
    cin >> n >> node1 >> node2;

    vector<int> edges(n);
    for (int i = 0; i < n; i++)
      cin >> edges[i];

    int res = closet_meeting_node(edges, node1, node2);
    cout << res << '\n';
  }

  return 0;
}
