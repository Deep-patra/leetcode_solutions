#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
  int low = 0, high = nums.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    cout << "low => " << low << " high => " << high << " mid => " << mid
         << endl;

    if (nums[mid] == target)
      return mid;

    // if nums[low] is less than nums[mid]
    // then the low and the mid are in the sorted section
    if (nums[mid] >= nums[low]) {
      if (nums[low] > target || nums[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    } else {
      // when only low is in the rotated section
      if (nums[low] <= target || nums[mid] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }
  }

  return -1;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, target;
    cin >> n >> target;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = search(nums, target);
    cout << result << endl;
  }

  return 0;
}
