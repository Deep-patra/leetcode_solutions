#include <iostream>
#include <vector>
using namespace std;

int find_min(vector<int> &nums) {
  int low = 0, high = nums.size() - 1, minimum = nums[0];

  while (low <= high) {
    int mid = low + (high - low) / 2;

    minimum = min(minimum, nums[mid]);

    if (nums[low] <= nums[mid]) {
      if (nums[high] < nums[mid])
        low = mid + 1;
      else
        high = mid - 1;
    } else {
      high = mid - 1;
    }
  }

  return minimum;
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

    int result = find_min(nums);
    cout << result << '\n';
  }

  return 0;
}
