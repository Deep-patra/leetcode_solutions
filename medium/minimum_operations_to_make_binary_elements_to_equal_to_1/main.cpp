#include <bits/stdc++.h>
using namespace std;

int min_operations(vector<int> &nums) {
  int i = 0, ops = 0;

  while (i < nums.size()) {
    
    if (nums[i] == 0) {
      if (i >= nums.size() - 2)
        return -1;

      for (int j = i; j < i + 3; j ++) 
        nums[j] = nums[j] == 0 ? 1 : 0;

      ops++;
    }

    i ++;
  }

  return ops;
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

    int result = min_operations(nums);
    cout << result << '\n';
  }

  return 0;
}
