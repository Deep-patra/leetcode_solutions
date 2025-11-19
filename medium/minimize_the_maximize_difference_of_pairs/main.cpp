#include <bits/stdc++.h>
using namespace std;

int find_pairs(vector<int> &nums, int diff) {
  int res = 0, n = nums.size();

  int i = 0;
  while (i < n - 1) {

    if (nums[i + 1] - nums[i] <= diff) {
      res++;
      i++;
    }

    i++;
  }

  return res;
}

int minimize_max(vector<int> &nums, int p) {

  int n = nums.size();

  sort(nums.begin(), nums.end());

  int low = 0, high = nums[n - 1] - nums[0], mid, res = high;

  while (low <= high) {

    mid = low + (high - low) / 2;

    if (find_pairs(nums, mid) >= p) {
      res = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, p;
    cin >> n >> p;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = minimize_max(nums, p);
    cout << res << '\n';
  }

  return 0;
}
