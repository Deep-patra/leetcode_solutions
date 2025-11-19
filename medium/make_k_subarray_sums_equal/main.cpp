#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;

ll make_sub_sum_equal(vector<int> &arr, int k) {
  int n = arr.size();

  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i ++)
      cin >> arr[i];

    ll res = make_sub_sum_equal(arr, k);
    cout << res << endl;
  }

  return 0;
}
