#include <bits/stdc++.h>
using namespace std;

int number_of_arithmetic_slices(vector<int> &nums) {
  int n = nums.size();

  if (nums.size() < 3)
    return 0;

  int res = 0, diff = INT_MIN, len = 1, curr = 0;

  for (int i = 1; i < n; i++) {    
    
    if ((nums[i] - nums[i - 1]) == diff) {
      len ++;

      if (len >= 3) {
        curr = (len - 3) + 1;
      }
    } else {

      diff = (nums[i] - nums[i - 1]);
      curr = 0;

      len = 2;
    }

    res += curr;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = number_of_arithmetic_slices(nums);
    cout << result << '\n';
  }

  return 0;
}
