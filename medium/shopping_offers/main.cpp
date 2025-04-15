#include <bits/stdc++.h>
using namespace std;

int dp[7][11];

// TODO: Complete the implementation
int shopping_offers(vector<int> &prices, vector<vector<int>> &special, vector<int> &needs) {
  int n = prices.size();
  memset(dp, 0, sizeof(dp));


}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
      cin >> prices[i];

    vector<vector<int>> special(n, vector<int>(n + 1));
    for (int i = 0; i < n; i++) 
      cin >> special[i][0] >> special[i][1] >> special[i][2];

    vector<int> needs(n);
    for (int i = 0; i < n; i++)
      cin >> needs[i];

    int result = shopping_offers(prices, special, needs);
    cout << result << '\n';

  }
    
  return 0;
}
