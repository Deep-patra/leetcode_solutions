#include <bits/stdc++.h>
using namespace std;

// INFO: Sliding Widnow Technique
int longest_nice_subarray(vector<int> &nums) {
  int result = 1, i = 0, j = 0;

  while (j < nums.size()) {
    if (i == j) {
      j ++;

      if (j == nums.size()) break;

      if (nums[i] & nums[j])
        i ++;

    }
    else {
      for (int idx = j - 1; idx >= i; idx --) {
        if (nums[j] & nums[idx]) {
          i = idx + 1;
          break;
        }
      }
      
      result = max(result, j - i + 1);
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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = longest_nice_subarray(nums);
    cout << result << '\n';
  }

  return 0;
}
