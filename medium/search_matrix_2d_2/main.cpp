#include <iostream>
#include <vector>
using namespace std;

bool search_matrix(vector<vector<int>> &matrix, int target) {
  int n = matrix.size(), m = matrix[0].size();


}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n, target;
    cin >> m >> n >> target;

    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];

    bool result = search_matrix(matrix, target);
    cout << result << '\n';
  }

  return 0;
}
