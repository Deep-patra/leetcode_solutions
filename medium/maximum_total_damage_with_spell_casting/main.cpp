#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maximum_total_damage(vector<int> &power) {
  int n = power.size();

  sort(power.begin(), power.end());

  vector<ll> max_arr(n, 0), dp(n, 0);
  dp[0] = power[0];
  max_arr[0] = power[0];

  auto bs = [&](int p) -> int {
    int l = 0, h = power.size() - 1, pos = -1;

    while (l <= h) {

      int mid = l + (h - l) / 2;

      if (power[mid] <= p) {
        pos = mid;
        l = mid + 1;
      } else
        h = mid - 1;
    }

    return pos;
  };

  for (int i = 1; i < n; i++) {
    if (power[i - 1] == power[i]) {
      dp[i] = dp[i - 1] + power[i];
    } else {

      int pos = bs(power[i] - 3);

      if (pos == -1) 
        dp[i] = power[i];
      else 
        dp[i] = max_arr[pos] + power[i]; 
    }


    max_arr[i] = max(max_arr[i - 1], dp[i]);
  }

  return max_arr[n - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> power(n);
    for (int i = 0; i < n; i++)
      cin >> power[i];

    ll res = maximum_total_damage(power);
    cout << res << endl;
  }

  return 0;
}
