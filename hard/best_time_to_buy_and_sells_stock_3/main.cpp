#include <iostream>
#include <vector>
using namespace std;

int max_profit(vector<int> prices) {
  
  if (prices.size() == 1)
    return 0;

  if (prices.size() == 2)
    return max(0, prices[1] - prices[0]);

  vector<vector<int>> dp(2, vector<int>(prices.size(), 0));

  int min_price = prices[0], max_profit;
  for (int i = 1; i < prices.size(); i++) {
    dp[0][i] = max(dp[0][i - 1], prices[i] - min_price);
    min_price = min(prices[i], min_price);
  }

  max_profit = dp[0][prices.size() - 1];

  int max_price = prices[prices.size() - 1];
  for (int i = prices.size() - 2; i > 1; i--) {
    dp[1][i] = max(dp[1][i + 1], dp[0][i - 1] + (max_price - prices[i]));

    max_price = max(max_price, prices[i]);
    max_profit = max(max_profit, dp[1][i]);
  }

  return max_profit;
}


int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> prices(n, 0);
    for (int i = 0; i < n; i++)
      cin >> prices[i];

    int profit = max_profit(prices);
    cout << profit << '\n';
  }

  return 0;
}
