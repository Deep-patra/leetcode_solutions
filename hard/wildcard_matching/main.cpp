#include <bits/stdc++.h>
using namespace std;

static bool dp[2001][2001];

bool is_match(string s, string p) {}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s, p;
    cin >> s >> p;

    bool result = is_match(s, p);
    cout << result << '\n';
  }

  return 0;
}
