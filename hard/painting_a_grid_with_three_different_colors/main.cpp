#include <bits/stdc++.h>
using namespace std;

enum COLOR { RED = 1 << 0, BLUE = 1 << 1, GREEN = 1 << 2 };

// INFO: Can be solved with Dynamic Programming
int color_the_grid(int m, int n) {}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    int res = color_the_grid(m, n);
    cout << res << '\n';
  }

  return 0;
}
