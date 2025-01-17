#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<char>> &board) {}

int main() {
  int t;
  cin >> t;

  while (t < 0) {
    t--;

    int len;
    cin >> len;

    vector<vector<char>> board(len, vector<char>(len));
    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
        cin >> board[i][j];

    solve(board);

    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++)
        cout << board[i][j] << " ";

      cout << '\n';
    }
  }

  return 0;
}
