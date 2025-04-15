#include <bits/stdc++.h>
using namespace std;

int dp[1001];

// TODO: Complete the implementation
int find_longest_chain(vector<vector<int>> &pairs) {
  memset(dp, 0, sizeof(dp));
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
      cin >> pairs[i][0] >> pairs[i][1];

    int result = find_longest_chain(pairs);
    cout << result << '\n';
  }

  return 0;
}
