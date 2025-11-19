#include <bits/stdc++.h>
using namespace std;

int num_teams(vector<int> &rating) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; i ++)
      cin >> ratings[i];

    int res = num_teams(ratings);
    cout << res << '\n';
  }

  return 0;
}
