#include <iostream>
#include <vector>
using namespace std;

int search_insert(vector<int> &nums, int target) {
  int low = 0, high = nums.size() - 1;

  if (target < nums[0])
    return 0;

  else if (target > nums[nums.size() - 1])
    return nums.size();

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
      return mid;

    if (nums[mid] > target)
      high = mid - 1;

    else if (nums[mid] < target)
      low = mid + 1;
  }

  return low;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int target, len;
    cin >> target >> len;

    vector<int> nums;
    for (int i = 0; i < len; i++) {
      int num;
      cin >> num;

      nums.push_back(num);
    }

    int result = search_insert(nums, target);

    cout << result << '\n';
  }

  return 0;
}
