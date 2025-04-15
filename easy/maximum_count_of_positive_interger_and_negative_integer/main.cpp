#include <bits/stdc++.h>
using namespace std;

int find_neg(vector<int> &nums) {
  int l = 0, r = nums.size() - 1, mid, pos = -1;
  
  while (l <= r) {
    mid = l + (r - l) / 2;

    if (nums[mid] < 0) {
      pos = mid;
      l = mid + 1;
    } else {
      r = mid  - 1;
    }
  }

  return pos == -1 ? 0 : pos + 1;
}

int find_pos(vector<int> &nums) {
  int l = 0, r = nums.size() - 1, mid, pos = -1;
  
  while (l <= r) {
    mid = l + (r - l) / 2;

    if (nums[mid] <= 0)
      l = mid + 1;
    else {
      pos = mid;
      r = mid - 1;
    }
  }

  return pos == -1 ? 0 : nums.size() - pos;
}

int maximum_count(vector<int> &nums) {
  return max(find_neg(nums), find_pos(nums));  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = maximum_count(nums);
    cout << res << '\n';
  }

  return 0;
}
