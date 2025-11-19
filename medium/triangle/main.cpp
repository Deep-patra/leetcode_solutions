#include <bits/stdc++.h>
using namespace std;

int minimum_total(vector<vector<int>> &triangle) {
  int l = triangle.size(), res = INT_MAX;

  vector<int> dp1(l, INT_MAX), dp2(l, INT_MAX);
  dp1[0] = triangle[0][0];

  for (int i = 1; i < l; i++) {

    dp2[0] = triangle[i][0] + dp1[0];

    for (int j = 1; j < i; j++)
      dp2[j] = min(triangle[i][j] + dp1[j - 1], triangle[i][j] + dp1[j]);

    dp2[i] = triangle[i][i] + dp1[i - 1];

    for (int k = 0; k < l; k++) {
      dp1[k] = dp2[k];
      dp2[k] = INT_MAX;
    }
  }

  for (int i = 0; i < l; i++)
    res = min(res, dp1[i]);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> triangles(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i + 1; j++) {
        int m;
        cin >> m;

        triangles[i].push_back(m);
      }
    }

    int res = minimum_total(triangles);
    cout << res << endl;
  }

  return 0;
}
