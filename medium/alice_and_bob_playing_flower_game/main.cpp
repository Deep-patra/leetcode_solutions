#include <bits/stdc++.h>
using namespace std;

ll flower_game(int n, int m) {

  long long a = 1LL * (n >> 1) * (m & 1 ? (m >> 1) + 1 : m >> 1);

  long long b = 1LL * (n & 1 ? (n >> 1) + 1 : n >> 1) * (m >> 1);

  return a + b;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    ll res = flower_game(n, m);
    cout << res << endl;
  }

  return 0;
}
