#include <bits/stdc++.h>
using namespace std;

int max_diff(int num) {

  string n = to_string(num);

  int a = num, b = num;

  auto swap_digits = [](string num, int d1, int d2) -> int {
    for (char &c : num) {
      int d = c - '0';

      if (d == d1)
        c = d2 + '0';
    }

    return stoi(num);
  };

  // get the maximum value
  int i = 0;
  while (i < n.length() && n[i] == '9')
    i++;

  if (i < n.length())
    a = swap_digits(n, n[i] - '0', 9);

  // get the minimum value
  // check if the y can be 0
  i = 1;
  while (i < n.length() && n[i] == '0' || swap_digits(n, n[i] - '0', 0) == 0 ||
         n[0] == n[i])
    i++;

  if (i < n.length())
    b = swap_digits(n, n[i] - '0', 0);

  for (int d = 1; d < 10; d++) {
    i = 0;

    while (i < n.length() && n[i] <= (d + '0'))
      i++;

    if (i < n.length()) {
      b = min(b, swap_digits(n, n[i] - '0', d));
      break;
    }
  }

  return a - b;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int res = max_diff(n);
    cout << res << '\n';
  }

  return 0;
}
