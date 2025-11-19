#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll min_cost(vector<int> &basket1, vector<int> &basket2) {
  int n = basket1.size();

  unordered_map<int, int> b1, b2;
  ordered_map<int, int> bmap1, bmap2;

  for (int val : basket1)
    b1[val]++;

  for (int val : basket2)
    b2[val]++;

  for (pair<int, int> p : b1) {
    if (b2.find(p.first) == b2.end())
      return -1;

    int d = p.second - b2[p.first];

    if (d & 1)
      return -1;

    if (d < 0)
      bmap2[p.first] = -1 * (d >> 1);
    else if (d > 0)
      bmap1[p.first] = d >> 1;
    else
      continue;

    b1.erase(p.first);
    b2.erase(p.first);
  }

  for (pair<int, int> p : b2) {
    if (b1.find(p.first) == b1.end())
      return -1;

    int d = p.second - b1[p.first];

    if (d & 1)
      return -1;

    if (d < 0)
      bmap1[p.first] = -1 * d;
    else if (d > 0)
      bmap2[p.first] = d;
    else
      continue;

    b1.erase(p.first);
    b2.erase(p.second);
  }

  // match the bigget value on the basket1 with the smallest value on basket2
  for (int i = bmap1.rbegin(); i != bmap1.rend(); i--) {
  }
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> basket1(n), basket2(n);
    for (int i = 0; i < n; i++)
      cin >> basket1[i];
    for (int i = 0; i < n; i++)
      cin >> basket2[i];

    ll res = min_cost(basket1, basket2);
    cout << res << '\n';
  }

  return 0;
}
