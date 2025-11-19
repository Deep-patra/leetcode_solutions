#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int binary_search(vector<int> &nums, int s, int e, int val, int lower) {
  if (s > e)
    return 0;

  int l = s, r = e, mid, pos = -1;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if ((nums[mid] + val) >= lower) {
      r = mid - 1;
      pos = mid;
    } else
      l = mid + 1;
  }

  if (pos == -1)
    return 0;

  return e - pos + 1;
}

void merge_sort(vector<int> &nums, int l, int r, int lower, int upper,
                ll &result) {
  if (l >= r)
    return;

  int mid = l + (r - l) / 2;

  merge_sort(nums, l, mid, lower, upper, result);
  merge_sort(nums, mid + 1, r, lower, upper, result);

  vector<int> v;

  int i = l, j = mid + 1;

  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {

      int res1 = binary_search(nums, mid + 1, r, nums[i], lower);
      int res2 = binary_search(nums, mid + 1, r, nums[i], upper + 1);

      result += max(res1 - res2, 0);

      v.push_back(nums[i++]);
    } else
      v.push_back(nums[j++]);
  }

  while (i <= mid) {
    int res1 = binary_search(nums, mid + 1, r, nums[i], lower);
    int res2 = binary_search(nums, mid + 1, r, nums[i], upper + 1);

    result += max(res1 - res2, 0);

    v.push_back(nums[i++]);
  }

  while (j <= r) {
    v.push_back(nums[j++]);
  }

  for (int i = l; i <= r; i++)
    nums[i] = v[i - l];
}

ll count_fair_pairs(vector<int> &nums, int lower, int upper) {
  ll result = 0;

  int n = nums.size();

  // sort(nums.begin(), nums.end());
  //
  // for (int i = 0; i < n - 1; i++) {
  //   int res1 = binary_search(nums, i + 1, nums[i], lower);
  //   int res2 = binary_search(nums, i + 1, nums[i], upper + 1);
  //
  //   int res = res1 - res2;
  //
  //   if (res < 0)
  //     break;
  //
  //   result += (ll)res;
  // }

  merge_sort(nums, 0, n - 1, lower, upper, result);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, lower, upper;
    cin >> n >> lower >> upper;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    ll result = count_fair_pairs(nums, lower, upper);
    cout << result << '\n';
  }

  return 0;
}
