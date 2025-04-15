#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// TODO: Complete the Implementation
//
// INFO: Use the Greedy - Sorting approach for this problem
ll put_marbles(vector<int> &weights, int k) {}

int main() {
  int t;
  cin >> t;

  int n, k;
  cin >> n >> k;

  vector<int> weights(n);
  for (int i = 0; i < n; i++)
    cin >> weights[i];

  ll result = put_marbles(weights, k);
  cout << result << '\n';

  return 0;
}
