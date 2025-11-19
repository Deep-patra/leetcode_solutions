#include <bits/stdc++.h>
using namespace std;

// Greedy Solution
int max_distance(string s, int k) {
  int n = s.length();

  int res = 0, d[4] = {0, 0, 0, 0};

  for (int i = 0; i < n; i++) {

    switch (s[i]) {
    case 'N':
      d[0]++;
      break;
    case 'S':
      d[2]++;
      break;
    case 'E':
      d[1]++;
      break;
    case 'W':
      d[3]++;
      break;
    default:
      break;
    }

    int t1 = min({d[0], d[2], k});
    int t2 = min({d[1], d[3], k - t1});

    int ans = 0;

    ans += abs(d[0] - d[2]) + 2 * t1;
    ans += abs(d[1] - d[3]) + 2 * t2;

    res = max(res, ans);
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int k;

    string s;
    cin >> s >> k;

    int res = max_distance(s, k);
    cout << res << '\n';
  }

  return 0;
}
