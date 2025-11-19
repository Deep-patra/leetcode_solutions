#include <bits/stdc++.h>
using namespace std;

// INFO: RUNTIME 0ms
void next_permutation(vector<int> &nums) {

  int n = nums.size();

  if (nums.size() == 1)
    return;

  pair<int, int> swap_indices = {-1, -1};

  for (int i = n - 1; i > 0 && i > swap_indices.second; i--) {

    for (int j = i - 1; j >= 0; j--)
      if (nums[i] > nums[j]) {
        if (swap_indices.second < j) {
          swap_indices = {i, j};
        }
      }
  }

  if (swap_indices.first != -1)
    swap(nums[swap_indices.first], nums[swap_indices.second]);

  // generate a smaller permutation after the index j
  int freq[101], j = swap_indices.second;
  memset(freq, 0, sizeof(freq));

  for (int i = j + 1; i < n; i++)
    freq[nums[i]]++;

  int idx = j + 1;
  int i = 0;

  while (idx < n && i < 101) {
    if (freq[i] > 0) {
      nums[idx] = i;
      freq[i]--;

      idx++;
    } else {
      i++;
    }
  }

  return;
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

    next_permutation(nums);

    for (int val : nums)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
