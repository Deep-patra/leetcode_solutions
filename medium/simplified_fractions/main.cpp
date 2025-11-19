#include <bits/stdc++.h>
using namespace std;

int __gcd(int a, int b) {
  if (b == 0)
    return a;

  return __gcd(b, a % b);
}

vector<string> simplified_fractions(int n) {

  vector<pair<int, int>> f;

  for (int den = 2; den <= n; den++) {

    for (int num = 1; num < den; num++) {
      if (__gcd(num, den) == 1)
        f.push_back({num, den});
    }
  }

  vector<string> fractions;

  for (pair<int, int> p : f)
    fractions.push_back(to_string(p.first) + "/" + to_string(p.second));

  return fractions;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<string> fractions = simplified_fractions(n);
    for (string s : fractions)
      cout << s << " ";

    cout << endl;
  }

  return 0;
}
