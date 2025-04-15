#include <iostream>
#include <vector>
using namespace std;

vector<int> search_range(vector<int> &nums, int target) {
  vector<int> result(2, -1);

  if (nums.size() == 0)
    return result;

  // check if the element is present in the array
  int low = 0, high = nums.size() - 1, mid;

  bool found = 0;

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (nums[mid] == target) {
      found = 1;
      break;
    }

    if (nums[mid] < target)
      low = mid + 1;

    else if (nums[mid] > target)
      high = mid - 1;
  }

  if (!found)
    return result;

  // find the start of the range

  low = 0;
  high = nums.size() - 1;

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (nums[mid] >= target)
      high = mid - 1;

    else if (nums[mid] < target)
      low = mid + 1;
  }

  result[0] = low;

  low = 0;
  high = nums.size() - 1;

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (nums[mid] > target)
      high = mid - 1;

    else if (nums[mid] <= target)
      low = mid + 1;
  }

  result[1] = high;

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len, target;
    cin >> target >> len;

    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    vector<int> result = search_range(nums, target);

    for (int val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
