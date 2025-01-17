#include <iostream>
#include <vector>
using namespace std;

// TODO: Implement the solution
void set_zeros(vector<vector<int>> &matrix) {
  
}


int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases --;

    int row, col;
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        cin >> matrix[i][j];

    set_zeros(matrix);

    for (int i = 0; i < row; i ++)
      for (int j = 0; j < col; j++)
        cout << matrix[i][j] << " ";

    cout << '\n';
  }

  return 0;
}
