#include <bits/stdc++.h>
using namespace std;

vector<int> apply_operations(vector<int> &nums) {
  // apply the operations
  for (int i = 0; i < nums.size() - 1; i++)
    if (nums[i] == nums[i + 1]) {
      nums[i] *= 2;
      nums[i + 1] = 0;
    }

  // shift all 0s to the end of the array using bubble sort
  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i] != 0) continue;

    int pos = i;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] != 0) {
        swap(nums[pos], nums[j]);
        pos = j;
      }
    }
  }

  return nums;
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

    vector<int> result = apply_operations(nums);
    
    for (int val : result)
      cout << val << " ";
    cout << '\n';
  }

  return 0;
}
