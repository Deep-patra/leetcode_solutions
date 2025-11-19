#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> get_positions(int n) {

  vector<vector<int>> temp(n, vector<int>(n, 0));

  vector<pair<int, int>> pos(n * n + 1);

  int p = 1;
  for (int i = 0; i < n; i++) {

    vector<int> t(n);

    for (int j = 0; j < n; j++)
      t[j] = p++;

    if (i & 1)
      reverse(t.begin(), t.end());

    temp[i] = t;
  }

  reverse(temp.begin(), temp.end());

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      pos[temp[i][j]] = make_pair(i, j);

  return pos;
}

// Using Breadth First Search Approach
int snakes_and_ladders(vector<vector<int>> &board) {

  int n = board.size();

  vector<int> rolls(n * n + 1, -1);

  vector<pair<int, int>> pos = get_positions(n);

  rolls[1] = 0;

  queue<int> q;
  q.push(1);

  while (!q.empty()) {

    int p = q.front();
    q.pop();

    int roll = rolls[p];

    for (int i = 1; i <= 6; i++) {

      int next = p + i;

      if (next > n * n)
        break;

      if (board[pos[next].first][pos[next].second] != -1) {
        int t = board[pos[next].first][pos[next].second];
        next = t;
      }

      if (rolls[next] != -1 && rolls[next] < roll + 1)
        continue;

      rolls[next] = rolls[next] == -1 ? roll + 1 : min(rolls[next], roll + 1);

      if (next == n * n)
        return rolls[next];

      q.push(next);
    }
  }

  return rolls[n * n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> board[i][j];

    int res = snakes_and_ladders(board);
    cout << res << '\n';
  }

  return 0;
}
