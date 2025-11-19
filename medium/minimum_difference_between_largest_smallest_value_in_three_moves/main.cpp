#include <bits/stdc++.h>
using namespace std;

int min_difference(vector<int> &nums) {
  int n = nums.size();

  sort(nums.begin(), nums.end());

   
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

    int res = min_difference(nums);
    cout << res << '\n';
  }
    
  return 0;
}
