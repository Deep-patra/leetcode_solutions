#include <iostream>
#include <vector>
using namespace std;

// INFO: 19ms Runtime
int coin_change(vector<int> &coins, int amount) {
  vector<int> dp(amount + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 0; i < coins.size(); i++) {
    for (int j = coins[i]; j <= amount; j ++) {
      if (dp[j - coins[i]] != INT_MAX) {
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
      }
    }
  }

  return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
      cin >> coins[i];

    int result = coin_change(coins, amount);
    cout << result << '\n';
  }

  return 0;
}
