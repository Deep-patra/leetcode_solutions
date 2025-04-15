#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longest_increasing_subsequence(vector<int> &nums) {
  vector<int> result;

  result.push_back(nums[0]);

  for (int i = 1; i < nums.size(); i++) {
    if (result.back() < nums[i])
      result.push_back(nums[i]);
    else {
      auto it = lower_bound(result.begin(), result.end(), nums[i]);

      int pos = distance(result.begin(), it);

      result[pos] = nums[i];
    }
  }

  return result.size();
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = longest_increasing_subsequence(nums);
    cout << result << '\n';
  }

  return 0;
}
