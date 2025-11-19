#include <bits/stdc++.h>  
using namespace std;

int max_coins(vector<int> &piles) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i ++)
      cin >> piles[i];

    int res = max_coins(piles);
    cout << res << endl;
  }

  return 0;
}
