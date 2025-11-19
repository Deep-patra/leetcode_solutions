#include <bits/stdc++.h>  
using namespace std;

// INFO: If there is not odd length cycle in the graph, then the graph is bipartite
bool possible_bipartition(int n, vector<vector<int>> &dislikes) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dislikes(m, vector<int>(2));
    for (int i = 0; i < m; i ++)
      cin >> dislikes[i][0] >> dislikes[i][1];

    bool res = possible_bipartition(n, dislikes);
    cout << res << '\n';
  }

  return 0;
} 
