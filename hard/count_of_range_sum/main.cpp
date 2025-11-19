#include <bits/stdc++.h>
using namespace std;

const int MAX 1e5 + 1;

pair<int, int> tree[MAX];

// Function to construct the segment tree
void construct_tree(const vector<int> &nums, int lower, int upper, int l, int r,
                    int si) {
  if (l > r)
    return;

  if (l == r) {
    tree[si] = { nums[l], nums[l] >= lower && nums[l] <= upper ? 1 : 0 };
    return;
  }

  int mid = l + (r - l) / 2;

  construct_tree(nums, lower, upper, l, mid, 2 * si + 1);
  construct_tree(nums, lower, upper, mid + 1, r, 2 * si + 2);

  tree[si] = { tree[2 * si + 1].first + tree[2 * si + 2].first , tree[2 * si + 1].second + tree[2 * si + 2].second };

  if (tree[si].first >= lower && tree[si].first <= upper)
    tree[si].second += 1;
}

int count_range_sum(vector<int> &nums, int lower, int upper) {
  // reset the segment tree
  for (int i = 0; i < MAX; i++)
    tree[i] = { 0, 0 };

  construct_tree(nums, lower, upper, 0, nums.size() - 1, 0);
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

    int result = count_range_sum(nums, lower, upper);
    cout << result << '\n';
  }

  return 0;
}
