#include <bits/stdc++.h>
using namespace std;

int x_dir[4] = {-1, 1, 0, 0}, y_dir[4] = {0, 0, 1, -1};

bool is_valid(vector<vector<char>> &board, vector<vector<bool>> &visited, int i,
              int j) {

  visited[i][j] = 1;

  int n = board.size(), m = board[0].size();

  if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
    return 0;

  bool valid = 1;
  for (int d = 0; d < 4; d++) {
    int r = i + x_dir[d], c = j + y_dir[d];

    if (r >= 0 && r <= n && c >= 0 && c <= m) {
      if (!visited[r][c] && board[r][c] == 'O' &&
          !is_valid(board, visited, r, c)) {
        valid = 0;
      }
    }
  }

  return valid;
}

void fill(vector<vector<char>> &board, int i, int j) {
  int n = board.size(), m = board[0].size();

  board[i][j] = 'X';

  for (int d = 0; d < 4; d++) {
    int r = i + x_dir[d], c = j + y_dir[d];

    if (r >= 0 && r < n && c >= 0 && c < m) {
      if (board[r][c] == 'O')
        fill(board, r, c);
    }
  }

}

void solve(vector<vector<char>> &board) {
  int n = board.size(), m = board[0].size();

  vector<vector<bool>> visited(n, vector<bool>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'O' && !visited[i][j]) {
        if (is_valid(board, visited, i, j)) {
          fill(board, i, j);
        }
      }
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> board[i][j];

    solve(board);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << board[i][j] << " ";

      cout << endl;
    }
  }

  return 0;
}
