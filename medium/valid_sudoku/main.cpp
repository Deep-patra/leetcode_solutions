#include <iostream>
#include <vector>
using namespace std;

bool is_valid_sudoku(vector<vector<char>> &board) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      char curr_ch = board[row][col];

      if (curr_ch == '.')
        continue;

      // check if the row is valid
      for (int row_index = 0; row_index < 9; row_index++)
        if (row_index != row && curr_ch == board[row_index][col])
          return false;

      // check if the column is valid
      for (int col_index = 0; col_index < 9; col_index++)
        if (col_index != col && curr_ch == board[row][col_index])
          return false;

      // check if the 3 x 3 box is valid
      int curr_box_row = int(row / 3) * 3;
      int curr_box_col = int(col / 3) * 3;

      for (int i = curr_box_row; i < curr_box_row + 3; i++)
        for (int j = curr_box_col; j < curr_box_col + 3; j++)
          if (i != row && j != col && board[i][j] == curr_ch)
            return false;
    }
  }

  return true;
}

void print_sudoku(vector<vector<char>> sudoku) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++)
      cout << sudoku[row][col] << " ";
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    vector<vector<char>> sudoku(9, vector<char>(9, '\0'));

    for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
        cin >> sudoku[row][col];

    bool result = is_valid_sudoku(sudoku);
    cout << result << '\n';
  }

  return 0;
}
