#include <bits/stdc++.h>  
using namespace std;

int count_subsets(const vector<int> &nums, int i, int curr_or, int max_or) {
  if (i >= nums.size()) return 0;

  int res = 0;

  if ((curr_or | nums[i]) == max_or) res ++;

  res += count_subsets(nums, i + 1, curr_or | nums[i], max_or) + count_subsets(nums, i + 1, curr_or, max_or) ;

  return res;
}

int count_max_or_subsets(vector<int> &nums) {
  int max_or = 0;

  for (int val : nums)
    max_or |= val;

  return count_subsets(nums, 0, 0, max_or);
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

    int res = count_max_or_subsets(nums);
    cout << res << '\n';
  }

  return 0;
}
