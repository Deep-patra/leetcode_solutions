#include <iostream>
#include <vector>
using namespace std;

int max_coins_recurse(vector<int> nums, vector<bool> bursted) {

  int result = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (!bursted[i]) {
      bursted[i] = 1;

      int l = 1, r = 1;

      for (int j = i - 1; j >= 0; j--)
        if (!bursted[j]) {
          l = nums[j];
          break;
        }

      for (int j = i + 1; j < nums.size(); j++)
        if (!bursted[j]) {
          r = nums[j];
          break;
        }

      int val = l * nums[i] * r;

      result = max(result, val + max_coins_recurse(nums, bursted));
      bursted[i] = 0;
    }
  }

  return result;
}

// INFO: Time Complexity will be N^3, Space Complexity will be N^3
int max_coins(vector<int> nums) {
  int len = nums.size();

  vector<vector<vector<int>>> dp(
      len, vector<vector<int>>(len, vector<int>(len, 0)));

  for (int i = 0; i < len; i++) {
    for (int j = i - 1; j >= 0; j--) {
      for (int k = i + 1; k < len; k++) {
        // calculate and store the values
        dp[i][j][k] = nums[j] * nums[i] * nums[k];
      }
    }
  }

  int result = 0;
  for (int i = 0; i < len; i++) {
    
  }

  return result;
}

int max_coins(vector<int> nums) {
  vector<bool> bursted(nums.size(), false);

  int result = max_coins_recurse(nums, bursted);

  return result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    int result = max_coins(nums);
    cout << result << '\n';
  }

  return 0;
}
