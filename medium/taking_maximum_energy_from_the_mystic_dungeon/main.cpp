#include <bits/stdc++.h>
using namespace std;

int maximum_energy(vector<int> &energy, int k) {
  int n = energy.size(), res = INT_MIN;

  vector<int> dp(n, INT_MIN);

  for (int i = 0; i < n; i++) {
    dp[i] = max(energy[i], dp[i]);

    if (i + k < n) {
      int max_val = dp[i];
      dp[i + k] = max(dp[i + k], max(energy[i + k], max_val + energy[i + k]));
    } else
      res = max(res, dp[i]);
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> energy(n);
    for (int i = 0; i < n; i++)
      cin >> energy[i];

    int res = maximum_energy(energy, k);
    cout << res << endl;
  }

  return 0;
}
