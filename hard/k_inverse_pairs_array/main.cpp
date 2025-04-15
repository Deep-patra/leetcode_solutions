#include <bits/stdc++.h>
using namespace std;

const int MOD = 10e9 + 7;

int k_inverse_pairs(int n, int k) {}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    int result = k_inverse_pairs(n, k);
    cout << result << '\n';
  }

  return 0;
}
