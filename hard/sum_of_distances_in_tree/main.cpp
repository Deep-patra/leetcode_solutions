#include <bits/stdc++.h>  
using namespace std;

// INFO: Can be solved with Binary Lifting and euler tour 
vector<int> sum_of_distances_in_tree(int n, vector<vector<int>> &edges) {
    
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i ++)
      cin >> edges[i][0] >> edges[i][1];

    vector<int> res = sum_of_distance_in_tree(n, edges);

    for (int v : res)
      cout << v << " ";
    cout << endl;
  }

  return 0;
}
