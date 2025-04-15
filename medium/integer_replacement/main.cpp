#include <bits/stdc++.h>
using namespace std;

static unordered_map<unsigned int, int> m;

int integer_replacement(int n) {
  if (n == 1)
    return 0;

  if (m.find(n) != m.end())
    return m[n];

  int res = INT_MAX;

  if (n & 1)
    res = min({res, integer_replacement(n - 1) + 1,
               integer_replacement(n + 1) + 1});

  else
    res = min(res, integer_replacement(n / 2) + 1);

  return m[n] = res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int result = integer_replacement(n);
    cout << result << '\n';
  }

  return 0;
}
