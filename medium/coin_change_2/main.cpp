#include <iostream>
#include <vector>
using namespace std;

int coin_change_memoization(vector<int> &coins, int amount,
                            vector<vector<int>> &dp, int index = 0) {

  if (amount == 0)
    return 1;

  if ((amount != 0 && amount < coins[0]) || amount < 0)
    return -1;

  if (dp[amount][index] != -1)
    return dp[amount][index];

  int result = 0;

  for (int i = index; i < coins.size(); i++) {
    int coin = coins[i];

    if (amount < coin)
      break;

    int ways = coin_change_memoization(coins, amount - coin, dp, i);

    if (ways != -1)
      result += ways;
  }

  dp[amount][index] = result;

  return result;
}

int coin_change_2_tabulation(vector<int> coins, int amount) {
  vector<int> dp(amount + 1, 0);

  dp[0] = 1;

  for (int coin : coins) {
    for (int i = coin; i <= amount; i++)
      dp[i] += dp[i - coin];
  }

  return dp[amount];
}

int coin_change_2(vector<int> coins, int amount) {
  // vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
  // return coin_change_memoization(coins, amount, dp);

  return coin_change_2_tabulation(coins, amount);
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

    int result = coin_change_2(coins, amount);
    cout << result << '\n';
  }

  return 0;
}
