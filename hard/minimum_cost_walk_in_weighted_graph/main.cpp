#include <bits/stdc++.h>
using namespace std;

// Uisng Disjoint set Union Approach
vector<int> minimum_cost(int n, vector<vector<int>> &edges, vector<vector<int>> &query) {
    
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
      cin >> edges[i][0] >> edges[i][1] >>edges[i][2];

    cin >> m;

    vector<vector<int>> query(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++) 
      cin >> query[i][0] >> query[i][1];

    vector<int> cost = minimum_cost(n, edges, query);
    for (int c : cost)
      cout << c << ' ';

    cout << '\n';
  }

  return 0;
}
