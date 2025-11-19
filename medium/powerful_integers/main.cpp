#include <bits/stdc++.h>
using namespace std;

vector<int> powerful_integers(int x, int y, int bound) {

  set<int> st;
  vector<int> res;

  int f = 1;
  while (f <= (bound - 1)) {

    int s = 1;
    while ((f + s) <= bound) {

      if (st.find(f + s) == st.end()) {
        st.insert(f + s);
        res.push_back(f + s);
      }

      s *= y;

      if (s == 1)
        break;
    }

    f *= x;

    if (f == 1)
      break;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int x, y, bound;
    cin >> x >> y >> bound;

    vector<int> res = powerful_integers(x, y, bound);

    sort(res.begin(), res.end());

    for (int val : res)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
