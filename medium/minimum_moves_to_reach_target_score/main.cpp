#include <bits/stdc++.h>
using namespace std;

int min_moves(int target, int max_doubles) {

  int curr = target, ops = 0;

  while (curr > 1) {
    
    if (curr & 1) {
      curr --;
      ops ++;
    } else {
      
      if (max_doubles > 0) {
        max_doubles --;
        curr >>= 1;
        ops ++;
      } else {
        ops += curr - 1;
        break;
      }

    }
  }

  return ops;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int target, max_doubles;
    cin >> target >> max_doubles;

    int res = min_moves(target, max_doubles);
    cout << res << endl;
  }

  return 0;
}
