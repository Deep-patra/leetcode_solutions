#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &nums, int low, int high) {
  int result = nums[low];

  while (low <= high) {
    int mid = low + (high - low) / 2;

    result = min(result, nums[mid]);

    if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
      result = min(result, binary_search(nums, low, mid - 1));
      result = min(result, binary_search(nums, mid + 1, high));
      break;
    }

    // if low and mid are both are in rotated sorted section
    if (nums[low] <= nums[mid]) {

      // if the section is rotated
      if (nums[high] <= nums[low])
        low = mid + 1;
      else
        high = mid - 1;

    } else
      high = mid - 1;
  }

  return result;
}

int find_minimum_sorted_array(vector<int> &nums) {
  return binary_search(nums, 0, nums.size() - 1);
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

    int result = find_minimum_sorted_array(nums);
    cout << result << endl;
  }

  return 0;
}
