#include <bits/stdc++.h>  
using namespace std;

int gcd(int a, int b) {
  
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

int min_operations(vector<int> &nums) {
  int n = nums.size(), min_ops = 0, one_count = 0;

  for (int val : nums)
    if (val == 1) one_count ++;

  // find if there is pair whose gcd is 1
  if (one_count == 0) {

    int cnt = 0;
    while (nums.size() > 0) {
      cnt ++;

      for (int i = 0, l = nums.size(); i < l - 1; i ++) {        
        int g = gcd(nums[i], nums[i + 1]);

        if (g == 1) 
          return cnt + n - 1;

        nums[i] = g;
      }    

      nums.pop_back();
    }

  } else 
    return n - one_count;

  return -1;
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

    int res = min_operations(nums);
    cout << res << endl;
  }

  return 0;
}
