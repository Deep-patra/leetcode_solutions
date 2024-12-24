#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      cout << matrix[i][j] << " ";
    }

    cout << '\n';
  }
}

void rotate(vector<vector<int>> &matrix) {

  int total_row = matrix.size();
  int total_col = matrix[0].size();

  for (int row = 0; row < total_row / 2; row++) {
    for (int col = 0; col < max_col - 1; col++) {

      /*
        matrix[row][col] - 1, 1
        matrix[row + col - 1][max_row - row]; - 2, 2
        matrix[max_row][max_col - col] - 3, 2
        matrix[max_col - col][row] - 2, 0
      **/

      int tmp = matrix[total_row - col - row][row];

      matrix[total_col - col + row][row] =
          matrix[total_row - row][total_col - col + row];

      matrix[total_row - row][total_col - col + row] =
          matrix[col][total_row - row];

      matrix[col + row][total_row - row] = matrix[row][col + row];
      matrix[row][col + row] = tmp;
    }
  }
}

int main() {

  // int testcases;
  // cin >> testcases;
  //
  // while (testcases > 0) {
  //   testcases--;
  //
  //   int len;
  //   cin >> len;
  //
  //   vector<vector<int>> matrix;
  //   for (int i = 0; i < len; i++) {
  //     vector<int> row;
  //
  //     for (int j = 0; j < len; j++) {
  //       int num;
  //       cin >> num;
  //
  //       row.push_back(num);
  //     }
  //
  //     matrix.push_back(row);
  //   }
  //   print_matrix(matrix);

  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  cout << "Before => " << endl;
  print_matrix(matrix);

  cout << endl << endl;

  rotate(matrix);
  cout << "After => " << endl;
  print_matrix(matrix);
  cout << endl << endl;

  vector<vector<int>> matrix1 = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

  cout << "Before => " << endl;
  print_matrix(matrix1);

  cout << endl << endl;

  rotate(matrix1);
  cout << "After => " << endl;
  print_matrix(matrix1);
  cout << endl << endl;
  // }

  return 0;
}
