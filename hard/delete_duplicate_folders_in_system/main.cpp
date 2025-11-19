#include <bits/stdc++.h>  
using namespace std;

// INFO: Complete the Implementation
vector<vector<string>> delete_duplicate_folder(vector<vector<string>> &paths) {
  int n = paths.size();


}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<vector<string>> paths(n, vector<string>(0));
    for (int i = 0; i < n; i ++) {
      int m;
      cin >> m;

      for (int j = 0; j < m; j ++) {
        string s;
        cin >> s;

        paths[i].push_back(s);
      }
    }

    vector<vector<string>> res = delete_duplicate_folder(paths);
    for (vector<string> l : res) {
      for (string s : l)
        cout << s << " ";

      cout << '\n';
    }
  }

  return 0;
}
