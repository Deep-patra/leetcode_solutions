#include <bits/stdc++.h>
using namespace std;

vector<int> pivot_array(vector<int> &nums, int pivot) {
  vector<int> result(nums.size(), 0);

  int cnt = 0;

  // fill the smallest 
  int j = 0;
  for (int i = 0; i < nums.size(); i ++) {
    if (nums[i] < pivot) {
      result[j] = nums[i];
      j ++;
    }

    if (nums[i] == pivot) cnt++;
  }

  while (cnt > 0) {
    result[j] = pivot;
    j ++;
    cnt --;
  }

  // fill the greater numbers
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > pivot) {
      result[j] = nums[i];
      j ++;
    }
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, pivot;
    cin >> n >> pivot;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    vector<int> result = pivot_array(nums, pivot);
    
    for (int val : result)
      cout << val << " ";
  }

  return 0;
}
