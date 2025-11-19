#include <bits/stdc++.h>
using namespace std;

int min_max_difference(int num) {

  string n = to_string(num);

  auto remap_digit = [](string n, int digit, int new_digit) -> int {
    for (char &c : n) {
      int d = c - '0';

      if (d == digit)
        c = new_digit + '0';
    }

    return stoi(n);
  };

  // digit to remap to get maximum value

  int maximum = num, minimum = num;

  int i = 0;
  while (i < n.length() && n[i] == '9')
    i++;

  if (i < n.length())
    maximum = remap_digit(n, n[i] - '0', 9);

  i = 0;
  while (i < n.length() && n[i] == '0')
    i++;

  if (i < n.length())
    minimum = remap_digit(n, n[i] - '0', 0);

  return maximum - minimum;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int res = min_max_difference(n);
    cout << res << '\n';
  }

  return 0;
}
