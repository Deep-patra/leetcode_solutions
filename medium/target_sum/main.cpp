#include <iostream>
#include <vector>
using namespace std;

int target_sum_recurse(vector<int> &nums, int target, int index = 0,
                       int curr_sum = 0) {

  if (curr_sum == target && index == nums.size())
    return 1;

  if (index >= nums.size())
    return 0;

  return target_sum_recurse(nums, target, index + 1, curr_sum + nums[index]) +
         target_sum_recurse(nums, target, index + 1,
                            curr_sum + (-1 * nums[index]));
}

int target_sum(vector<int> &nums, int target) {
  vector<int> memo(nums.size() + 1, INT_MIN);

  return target_sum_recurse(nums, target, memo);
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len, target;
    cin >> len >> target;

    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    int result = target_sum(nums, target);
    cout << result << '\n';
  }

  return 0;
}
