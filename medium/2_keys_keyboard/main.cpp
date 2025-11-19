#include <bits/stdc++.h>
using namespace std;

int max_odd_frac(int n) {
  int odd = 1;

  for (int i = n - 1; i >= 1; i--)
    if ((i & 1) && n % i == 0)
      return i;

  return odd;
}

int min_steps(int n) {

  if (n == 1)
    return 0;

  if (n == 2)
    return 2;

  if (n & 1) {
    int f = max_odd_frac(n);

    // if it doesn't have a odd factor other than 1, then it is a prime
    if (f == 1)
      return n;

    return min_steps(f) + (n / f);
  }

  return 2 + min_steps(n >> 1);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int result = min_steps(n);
    cout << result << '\n';
  }

  return 0;
}
