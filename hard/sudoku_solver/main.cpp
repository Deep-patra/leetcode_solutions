#include <iostream>
#include <vector>
using namespace std;

void print_board(vector<vector<char>> &board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++)
      cout << board[i][j] << ' ';

    cout << '\n';
  }
}

// check if the current character is valid or not
bool is_valid(vector<vector<char>> &board, int row, int col) {
  char curr_char = board[row][col];

  // check the row
  for (int i = 0; i < 9; i++)
    if (i != col && curr_char == board[row][i])
      return false;

  // check the column
  for (int i = 0; i < 9; i++)
    if (i != row && curr_char == board[i][col])
      return false;

  // check the current block
  int block_row = int(row / 3) * 3;
  int block_col = int(col / 3) * 3;

  for (int i = block_row; i < block_row + 3; i++)
    for (int j = block_col; j < block_col + 3; j++)
      if (i != row && j != col && curr_char == board[i][j])
        return false;

  return true;
}

bool solve(vector<vector<char>> &board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {

      if (board[i][j] == '.') {

        for (char ch = '1'; ch <= '9'; ch++) {
          board[i][j] = ch;
          if (is_valid(board, i, j) && solve(board))
            return true;
        }

        board[i][j] = '.';
        return false;
      }
    }
  }

  return true;
}

void solve_sudoku(vector<vector<char>> &board) { solve(board); }

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    vector<vector<char>> board(9, vector<char>(9, '.'));
    for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
        cin >> board[row][col];

    solve_sudoku(board);

    print_board(board);
  }

  return 0;
}
