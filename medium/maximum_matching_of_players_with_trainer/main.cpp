#include <bits/stdc++.h>  
using namespace std;

int match_players_and_trainers(vector<int> &players, vector<int> &trainers) {
  
  qsort(players.begin(), players.end());
  qsort(trainers.begin(), trainers.end());

  int i = 0, j = 0, res = 0;
  while (i < players.size() && j < trainers.size()) {
    
    if (players[i] > trainers[j]) {
      j ++;
    } else {
      i ++;
      j ++;

      res ++;
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<int> players(n), trainers(m);
    for (int i = 0; i < n; i ++)
      cin >> players[i];

    for (int i = 0; i < m; i ++)
      cin >> trainers[i];

    int res = match_players_and_trainers(players, trainers);
    cout << res << '\n';
  }

  return 0;
}
