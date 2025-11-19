#include <bits/stdc++.h>
using namespace std;

int find_earlier_round(list<int> &l, int f, int s) {}

int find_latest_round(list<int> &l, int f, int s) {}

vector<int> earlier_and_latest(int n, int firstPlayer, int secondPlayer) {
  list<int> l;

  for (int i = 1; i < n; i++)
    l.push_back(i);

  return vector<int>{
      find_earlier_round(l, firstPlayer, secondPlayer),
      find_latest_round(l, firstPlayer, secondPlayer),
  };
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, first_player, second_player;
    cin >> n >> first_player >> second_player;

    vector<int> res = earlier_and_latest(n, first_player, second_player);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
