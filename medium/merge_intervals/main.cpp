#include <iostream>
#include <vector>
using namespace std;

// TODO: Implement the Solution
vector<vector<int>> merge(vector<vector<int>> &intervals) {

  vector<vector<int>> result;

  int low = intervals[0][0], high = intervals[0][1];
  for (int i = 1; i < intervals.size(); i++) {
    int l = intervals[i][0], h = intervals[i][1];

    if (low >= l && high <= l && h > high) 
      high = h;

    else if (l > high) {
      vector<int> v(2, 0);

      v[0] = low;
      v[1] = high;

      result.push_back(v);

      low = l;
      high = h;
    }

  }

  return result;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> intervals(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> intervals[i][j];

    vector<vector<int>> result = merge(intervals);

    for (vector<int> list : result) {
      for (int val: list)
        cout << val << " ";

      cout << '\n';
    }
  }

  return 0;
}
