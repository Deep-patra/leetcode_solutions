#include <bits/stdc++.h>  
using namespace std;

int sum_integers(int a, int b) {

  int sum = 0;

  bool carry = 0;
  for (int i = 0; i < 32; i ++) {
    bool f = (a & (1 << i)), s = (b & (1 << i)), r;

    if (f & s) {

      if (carry) 
        res = 1;
      else {
        res = 0;
        carry = 1;
      }

    } else {

      if (f | s) {
        
        if (carry) {
          res = 0;
        }
        else {
          res = 1;
        }

      } else {
        res = carry;
        carry = 0;
      }

    }

    if (r) sum |= (1 << i);
  }

  return sum;

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int a, b;
    cin >> a >> b;

    int res = sum_integers(a, b);
    cout << res << '\n';
  }

  return 0;
}
