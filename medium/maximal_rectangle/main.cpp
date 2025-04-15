#include <iostream>
#include <vector>
using namespace std;

int maximal_rectangle(vector<vector<int>> &matrix) {}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<char>> matrix(m, vector<char>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];

    int result = maximal_rectangle(matrix);
    cout << result << '\n';
  }

  return 0;
}
