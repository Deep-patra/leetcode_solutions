#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {

  vector<vector<int>> result(0);

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 3; i++) {

    if (i > 0 && nums[i] == nums[i - 1]) continue;

    for (int j = i + 1; j < nums.size() - 2; j++) {
      
      if ( j > i + 1 && nums[j] == nums[j - 1]) continue;

      // using two pointer technique 
      int l = j + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[j] + nums[l] + nums[r];

        if (sum == target) {
          result.push_back({ nums[i], nums[j], nums[l], nums[r] });
          l ++;
          r --;

          // skip duplicates
          while (l < r && nums[l] == nums[l - 1]) l++;
          while (l < r && nums[r] == nums[r + 1]) r--;
        }


        else if (sum < target) 
          l ++;

        else 
          r --;
      }

    }

  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, target;
    cin >> n >> target;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    vector<vector<int>> result = fourSum(nums, target);

    for (vector<int> list : result) {
      for (int val : list)
      cout << val << " ";

      cout << '\n';
    }
  }


  return 0;
}
