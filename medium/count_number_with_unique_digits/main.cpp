#include <bits/stdc++.h>  
using namespace std;

int memo[9][9][1 << 11];

int get_digits(int digits, int mask, int pos) {

  if (memo[digits][pos][mask] != -1)
    return memo[digits][pos][mask];

  int res = 0;

  int i = (pos != 0) ? 0 : 1;

  for (; i < 10; i ++) {
    if (!(mask & (1 << i))) {
      if (pos == digits - 1) {
        res ++;
        continue;
      }


      res += get_digits(digits, mask | (1 << i), pos + 1);
    }
  } 

  return memo[digits][pos][mask] = res;
}

int count_number_with_unique_digits(int n) {

  if (n == 0) return 1;

  memset(memo, -1, sizeof(memo));

  int res = 10;

  for (int i = 2; i <= n; i ++) {
    res += get_digits(i, 0, 0);        
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

    int res = count_number_with_unique_digits(n);
    cout << res << '\n';
  }

  return 0;
}
