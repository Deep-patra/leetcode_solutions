#include <bits/stdc++.h>  
using namespace std;

int min_k_bit_flops(vector<int> &nums, int k) {
  int n = nums.size();


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

    int res = min_k_bit_flops(nums, k);
    cout << res << endl;
  }

  return 0;
}
