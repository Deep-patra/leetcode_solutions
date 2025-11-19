#include <bits/stdc++.h>  
using namespace std;

// TODO: Complete the Implementation
bool contains_pattern(vector<int> &arr, int m, int k) {
  int n = arr.size(), l = 0, r = 0;

  

  while (r < n) {
    if (r - l < m) {
      r ++;


    }
  }

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i ++)
      cin >> arr[i];

    int res = contains_pattern(arr, m, k);
    cout << res << '\n';
  }

  return 0;
}
