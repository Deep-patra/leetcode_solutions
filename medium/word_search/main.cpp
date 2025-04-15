#include <bits/stdc++.h>
using namespace std;

const int rows[] = { -1, 1, 0, 0 };
const int cols[] = { 0, 0, -1, 1 };

bool dfs(vector<vector<char>> &board, bool visited[6][6], string word, int idx, int row, int col) {
  if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0)
    return false;

  if (idx >= word.length())
    return true;

  if (visited[row][col] || board[row][col] != word[idx])
    return false;

  visited[row][col] = 1;

  for (int i = 0; i < 4; i++) 
    if (dfs(board, visited, word, idx + 1, row + rows[i], col + cols[i]))
      return true;

  visited[row][col] = 0;

  return false;
}

static bool visited[6][6];

bool exist(vector<vector<char>> &board, string word) {
  int m = board.size(), n = board[0].size();

  for (int i = 0; i < m; i++) 
    for (int j = 0; j < n; j ++) 
      if (board[i][j] == word[0]) {
          memset(visited, 0, sizeof(visited));

          if (dfs(board, visited, word, 0, i, j))
            return true;
        }

  return false;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string word;
    int m, n;
    cin >> m >> n >> word;

    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) 
      for (int j = 0; j < n; j++) 
        cin >> board[i][j];

    bool result = exist(board, word);
    cout << result << '\n';
  }

  return 0;
}
