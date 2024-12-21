#include <iostream>
#include <vector>
using namespace std;

int search_insert(vector<int> &nums, int target) {

  if (nums.size() == 1) {
    return nums[0] > target ? 0 : 1;
  }

  int low = 0;
  int high = nums.size() - 1;

  int mid = low + (high - low) / 2;

  while (low < high) {
    mid = low + (high - low) / 2;

    if (nums[mid] == target)
      return mid;

    if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid;
  }

  return mid;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int target;
    cin >> target;

    int len;
    cin >> len;

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
