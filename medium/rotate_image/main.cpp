#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>> matrix) {
  int n = matrix.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }

    cout << '\n';
  }
}

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();

  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
      swap(matrix[i][j], matrix[j][i]);

  for (int i = 0; i < n; i++)
    reverse(matrix[i].begin(), matrix[i].end());
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<vector<int>> matrix(len, vector<int>(len));
    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
        cin >> matrix[i][j];

    rotate(matrix);

    print_matrix(matrix);
  }

  return 0;
}
