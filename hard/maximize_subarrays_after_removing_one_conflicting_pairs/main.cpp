#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;

// INFO: Editorial solves this problem using Enumeration Approach
//
// TODO: Complete this Implementation
ll max_subarrays(int n, vector<vector<int>> &conflictingPairs) {
  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> conflicting_pairs(m, vector<int> (2));
    for (int i = 0; i < m; i ++)
      cin >> conflicting_pairs[i][0] >> conflicting_pairs[i][1];

    ll res = max_subarrays(n, conflicting_pairs);
    cout << res << '\n'; 
  }

  return 0;
}
