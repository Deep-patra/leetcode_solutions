#include <bits/stdc++.h>
using namespace std;

int count_reverse_pairs(vector<int> &nums, int l, int mid, int r) {
  int cnt = 0;

  int j = mid + 1;
  for (int i = l; i <= mid; i++) {
    while (j <= r && nums[i] > 2 * nums[j])
      j++;

    cnt += (j - (mid + 1));
  }

  return cnt;
}

void merge_sort(vector<int> &nums, int l, int r, int &result) {

  if (l == r)
    return;

  int mid = l + (r - l) / 2;

  merge_sort(nums, l, mid, result);
  merge_sort(nums, mid + 1, r, result);

  result += count_reverse_pairs(nums, l, mid, r);

  vector<int> res(r - l + 1);

  int i = l, j = mid + 1, k = 0;

  while (i <= mid && j <= r) {
    if (nums[i] < nums[j])
      res[k++] = nums[i++];
    else
      res[k++] = nums[j++];
  }

  while (i <= mid)
    res[k++] = nums[i++];

  while (j <= r)
    res[k++] = nums[j++];

  for (int i = 0; i < res.size(); i++)
    nums[l + i] = res[i];

  return;
}

// INFO: Using Merge Sort Approach
int reverse_pairs(vector<int> &nums) {
  int result = 0;

  merge_sort(nums, 0, nums.size() - 1, result);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = reverse_pairs(nums);
    cout << result << '\n';
  }

  return 0;
}
