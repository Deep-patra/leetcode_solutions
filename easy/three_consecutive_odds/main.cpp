#include <bits/stdc++.h>
using namespace std;

bool three_consecutive_odds(vector<int> &nums) {
  int n = nums.size(), l = 0;

  for (int i = 0; i < n; i ++) {
    if (nums[i] & 1) l ++;
    if (l == 3) return true;
  }
  
  return false;
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

    bool res = three_consecutive_odds(nums);
    cout << res << '\n';
  }

  return 0;
}
