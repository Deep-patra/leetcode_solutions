#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*
  Dynamic Programming on Broken Profile Problem
*/
int num_tilings(int n) {
  
  if (n == 1) return 1;

  int res = 0;
  
  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    int res = num_tilings(n);
    cout << res << '\n';
  }

  return 0;
}
