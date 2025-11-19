#include <bits/stdc++.h>  
using namespace std;

// TODO: Implement a solution
int max_value(vector<int> &nums, int k) {
  int n = nums.size();

  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k; 
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int val = max_val(nums, k);
    cout << val << '\n';
  }

  return 0;
}
