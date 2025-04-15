#include <bits/stdc++.h>
using namespace std;

int dp[366][3];

int min_cost_tickets(vector<int> &days, vector<int> &costs) {
  int n = days.size();
  memset(dp, 0, sizeof(dp));

  for (int c = 0; c < 3; c ++) {
    
    for (int i = 1; i <= 365; i ++) {
      
    }

  }

  return dp[n - 1][3];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> costs(3); 
    cin >> costs[0] >> costs[1] >> costs[2];

    vector<int> days(n);
    for (int i = 0; i < n; i ++)
      cin >> days[i];

    int result = min_cost_tickets(days, costs);
    cout << result << '\n';
  }

  return 0;
}
