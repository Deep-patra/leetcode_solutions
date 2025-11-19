#include <bits/stdc++.h>
using namespace std;

// TODO: Complete the Implementation
double new_21_game(int n, int k, int maxPts) {}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k, max_pts;
    cin >> n >> k >> max_pts;

    double res = new_21_game(n, k, max_pts);
    cout << res << '\n';
  }

  return 0;
}
