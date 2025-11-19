#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<pair<int, int>> &nums, int k, int l, int r,
                int &result) {
  if (l >= r)
    return;

  int mid = l + (r - l) / 2;
  merge_sort(nums, k, l, mid, result);
  merge_sort(nums, k, mid + 1, r, result);

  vector<pair<int, int>> merged_values;

  int i = l, j = mid + 1;

  while (i <= mid && j <= r) {
    if (nums[i].first <= nums[j].first) {
      merged_values.push_back(nums[i]);

      int temp = j;
      while (temp <= r && nums[i].first == nums[temp].first) {
        result += (nums[i].second * nums[temp].second) % k == 0;
        temp++;
      }

      i++;
    } else {
      merged_values.push_back(nums[j]);
      j++;
    }
  }

  while (i <= mid)
    merged_values.push_back(nums[i++]);

  if (j <= r)
    merged_values.push_back(nums[j++]);

  while (j <= r) {
    if (nums[i - 1].first == nums[j].first)
      result += (nums[i - 1].second * nums[j].second) % k == 0;

    merged_values.push_back(nums[j++]);
  }

  for (int i = l; i <= r; i++)
    nums[i] = merged_values[i - l];
}

int count_pairs(vector<int> &nums, int k) {
  int result = 0;

  vector<pair<int, int>> mapped_nums(nums.size());

  for (int i = 0; i < nums.size(); i++)
    mapped_nums[i] = {nums[i], i};

  merge_sort(mapped_nums, k, 0, nums.size() - 1, result);

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = count_pairs(nums, k);
    cout << result << '\n';
  }

  return 0;
}
