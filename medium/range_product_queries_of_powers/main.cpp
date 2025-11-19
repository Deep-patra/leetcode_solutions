#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int exp(int x, int pow) {

  int res = 1;
  while (pow > 0) {

    if (pow & 1)
      res = res * x % MOD;

    x = x * x % MOD;
    pow >>= 1;
  }

  return res;
}

vector<int> product_queries(int n, vector<vector<int>> &queries) {

  vector<int> powers, res;

  while (n > 0) {

    int pow = 0;
    while (pow < 31 && (1 << pow) <= n) {
      pow++;
    }

    if (pow > 0)
      pow--;

    powers.push_back(pow);
    n -= (1 << pow);
  }

  reverse(powers.begin(), powers.end());

  vector<int> pref(powers.size() + 1, 0);

  for (int i = 0; i < powers.size(); i++)
    pref[i + 1] = pref[i] + powers[i];

  for (int i = 0; i < queries.size(); i++) {
    vector<int> q = queries[i];

    int pow = pref[q[1] + 1] - pref[q[0]];
    res.push_back(exp(2, pow));
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
      cin >> queries[i][0] >> queries[i][1];

    vector<int> res = product_queries(n, queries);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
