#include <bits/stdc++.h>
using namespace std;

// TOOD: Complete the Implementation, Cannot find the approach 😟
int shortest_path_length(vector<vector<int>> &graph) {


}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
      int l;
      cin >> l;

      graph[i].resize(l);
      for (int j = 0; j < l; j++)
        cin >> graph[i][j];
    }

    int path = shortest_path_length(graph);
    cout << path << '\n';
  }

  return 0;
}
