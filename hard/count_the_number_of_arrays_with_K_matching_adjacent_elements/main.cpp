#include <bits/stdc++.h>
using namespace std;

int count_good_adjacent_elements(int n, int m, int k) {
  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m, k;
    cin >> n >> m >> k;

    int res = count_good_adjacent_elements(n, m, k);
    cout << res << '\n';
  }

  return 0;
}
