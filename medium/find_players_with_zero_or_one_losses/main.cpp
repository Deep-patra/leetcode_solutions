#include <bits/stdc++.h>
using namespace std;

// INFO: Solved but a bit slower than the others
vector<vector<int>> find_winners(vector<vector<int>> &matches) {
  int n = matches.size();

  map<int, pair<int, int>> m;

  vector<vector<int>> res(2, vector<int>(0));

  for (int i = 0; i < n; i ++) {
    m[matches[i][0]].first ++;
    m[matches[i][1]].second ++;
  }

  for (pair<int, pair<int, int>> p : m) {
    if (p.second.first > 0 && p.second.second == 0)
      res[0].push_back(p.first);

    if (p.second.second == 1)
      res[1].push_back(p.first);
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  int n;
  cin >> n;

  vector<vector<int>> matches(n, vector<int>(2, 0));
  for (int i = 0; i < n; i ++)
    cin >> matches[i][0] >> matches[i][1];

  vector<vector<int>> res = find_winners(matches);

  for (vector<int> p : res) {
    for (int val : p)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
