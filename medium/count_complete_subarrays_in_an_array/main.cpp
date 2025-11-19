#include <bits/stdc++.h>
using namespace std;

int count_complete_subarrays(vector<int> &nums) {
  int total_unique = 0, n = nums.size();

  int freq[2001];
  memset(freq, 0, sizeof(freq));

  for (int val : nums) {
    freq[val]++;

    if (freq[val] == 1)
      total_unique++;
  }

  // sliding window approach
  int i = 0, j = 0, curr_unique = 1, result = 0;
  memset(freq, 0, sizeof(freq));

  freq[nums[0]]++;

  while (i <= j && j < n) {
    if (curr_unique == total_unique) {
      result += 1 + (n - (j + 1));

      freq[nums[i]]--;

      if (freq[nums[i]] == 0)
        curr_unique--;

      if (i == j) {

        if (j == n - 1)
          break;

        i++;
        freq[nums[i]]++;

        if (freq[nums[i]] == 1)
          curr_unique++;

        j = i;
      } else
        i++;

    } else if (curr_unique < total_unique) {
      if (j == n - 1)
        break;

      j++;
      freq[nums[j]]++;

      if (freq[nums[j]] == 1)
        curr_unique++;
    } else {
      freq[nums[i]]--;

      if (freq[nums[i]] == 0)
        curr_unique--;

      i++;
    }
  }

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

    int result = count_complete_subarrays(nums);
    cout << result << '\n';
  }

  return 0;
}
