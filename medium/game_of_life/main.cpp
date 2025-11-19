#include <bits/stdc++.h>
using namespace std;

int x_dir[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    y_dir[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void game_of_life(vector<vector<int>> &board) {
  int m = board.size(), n = board[0].size();

  vector<vector<int>> b(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {

      int live = 0;
      for (int d = 0; d < 8; d++) {

        int r = i + x_dir[d], c = j + y_dir[d];

        if (r >= 0 && r < m && c >= 0 && c < n)
          if (board[r][c] == 1)
            live++;
      }

      if (board[i][j] == 1) {
        if (live < 2 || live > 3)
          b[i][j] = 0;

        else
          b[i][j] = 1;

      } else {

        if (live == 3)
          b[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      board[i][j] = b[i][j];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> board(m, vector<int>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> board[i][j];

    game_of_life(board);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        cout << board[i][j] << " ";

      cout << endl;
    }
  }

  return 0;
}
