#include <iostream>
#include <vector>
using namespace std;

int first_complete_index(vector<int> &arr, vector<vector<int>> &mat) {

  if (arr.size() == 1)
    return 0;

  int m = mat.size(), n = mat[0].size();
  vector<pair<int, int>> mat_location(arr.size() + 1);

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      mat_location[mat[i][j]] = make_pair(i, j);

  vector<int> rows(m, 0);
  vector<int> cols(n, 0);

  for (int i = 0; i < arr.size(); i++) {
    int val = arr[i];
    int row = mat_location[val].first, col = mat_location[val].second;

    rows[row]++;
    cols[col]++;

    if (rows[row] == n || cols[col] == m)
      return i;
  }

  return 0;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len, m, n;
    cin >> len;

    vector<int> arr(len);
    for (int i = 0; i < len; i++)
      cin >> arr[i];

    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> mat[i][j];

    int result = first_complete_index(arr, mat);
    cout << result << '\n';
  }

  return 0;
}
