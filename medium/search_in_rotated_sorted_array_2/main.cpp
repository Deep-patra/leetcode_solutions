#include <bits/stdc++.h>
using namespace std;

// INFO: Finally Solved it 
bool binary_search(vector<int> &nums, int l, int r, int target) {

  while (l <= r) {

    int mid = l + (r - l) / 2;

    if (nums[mid] == target || nums[l] == target || nums[r] == target) return true;

    if (l != r && nums[l] == nums[mid] && nums[r] == nums[mid])
      return binary_search(nums, l, mid, target) ||
             binary_search(nums, mid + 1, r, target);


    if (nums[mid] <= nums[r] && nums[mid] < nums[l]) {

      if (target < nums[mid] || (target > nums[mid] && target > nums[r]))
        r = mid - 1;
      else 
        l = mid + 1;

    } else if (nums[mid] > nums[r] && nums[mid] >= nums[l]) {

      if (target > nums[mid] || (target < nums[mid] && target < nums[r]))
        l = mid + 1;
      else 
        r = mid - 1;

    } else {

      if (target > nums[mid])
        l = mid + 1;
      else 
        r = mid - 1;

    }
  }

  return false;
}

bool search(vector<int> &nums, int target) {
  return binary_search(nums, 0, nums.size() - 1, target);
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

    bool result = search(nums, target);
    cout << result << "\n";
  }

  return 0;
}
