#include <bits/stdc++.h>
using namespace std;

vector<int> max_subsequence(vector<int> &nums, int k) {
  int n = nums.size();

  if (n == k)
    return nums;

  vector<int> indices(n), res(k);

  for (int i = 0; i < n; i++)
    indices[i] = i;

  auto comparator = [&](int &idx1, int &idx2) -> bool {
    return nums[idx1] > nums[idx2];
  };

  sort(indices.begin(), indices.end(), comparator);

  for (int i = n - 1; i >= 0 && i >= k; i--)
    indices.pop_back();

  sort(indices.begin(), indices.end());

  for (int i = 0; i < k; i++)
    res[i] = nums[indices[i]];

  return res;
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

    vector<int> res = max_subsequence(nums, k);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
