#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &nums, int low, int high) {
  int result = nums[low];

  while (low <= high) {
    int mid = low + (high - low) / 2;
  }

  return result;
}

int find_peak_element(vector<int> &nums) {
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

    int result = find_peak_element(nums);
    cout << result << '\n';
  }

  return 0;
}
