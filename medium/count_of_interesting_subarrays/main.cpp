#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// TODO: Complete the implementation
ll count_interesting_subarrays(vector<int> &nums, int modulo, int k) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, modulo, k;
    cin >> n >> modulo >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    ll res = count_interesting_subarrays(nums, modulo, k);
    cout << res << '\n';
  }

  return 0;
}
