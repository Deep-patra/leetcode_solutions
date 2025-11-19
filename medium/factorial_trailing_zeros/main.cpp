#include <bits/stdc++.h>  
using namespace std;

int trailing_zeros(int n) {

  if (n == 0) return 0;

  int res = 0, curr = 1;

  for (int i = 1; i <= n; i ++) {    
    curr *= i;
  
    while (curr % 10 == 0) {
      res ++;
      curr /= 10;
    }

    curr %= 10;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    int res = trailing_zeros(n);
    cout << res << endl;
  }

  return 0;
}
