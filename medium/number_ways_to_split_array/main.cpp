#include <iostream>
#include <vector>
using namespace std;

int ways_to_split_array(vector<int> &nums) {

  vector<long long> prefix_sum(nums.size());
  prefix_sum[0] = nums[0];

  for (int i = 1; i < nums.size(); i++)
    prefix_sum[i] = nums[i] + prefix_sum[i - 1];

  int max_ways = 0;

  for (int i = 0; i < nums.size() - 1; i++) {
    long left_sum = prefix_sum[i];
    long right_sum = prefix_sum[nums.size() - 1] - prefix_sum[i];

    if (left_sum >= right_sum)
      max_ways++;
  }

  return max_ways;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    int result = ways_to_split_array(nums);

    cout << result << '\n';
  }

  return 0;
}
