#include <bits/stdc++.h>
using namespace std;

int dp[1001][101][2];

int max_profit(int k, vector<int> &prices) {
  int n = prices.size();

  memset(dp, 0, sizeof(dp));

  for (int j = 1; j <= k; j ++) {
    for (int i = j - 1; i < n; i++) {
      
      

    }
  }

  return dp[n - 1][k][1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
      cin >> prices[i];

    int profit = max_profit(k, prices);
    cout << profit << '\n';
  }

  return 0;
}
