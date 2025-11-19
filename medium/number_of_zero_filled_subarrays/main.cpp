#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;

ll zero_filled_subarray(vector<int> &nums) {

  ll res = 0;

  int cnt = 0;
  for (int val : nums) {
    if (val == 0) {
      cnt ++;

      res += (cnt - 1) + 1;
    } 

    else 
      cnt = 0;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    ll res = zero_filled_subarray(nums);
    cout << res << '\n';
  }

  return 0;
}
