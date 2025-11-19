#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> divide_array(vector<int> &nums, int k) {
  int n = nums.size(), s = n / 3;

  sort(nums.begin(), nums.end());

  vector<vector<int>> res(n / 3, vector<int>(3));

  int i = 0, j = 0;
  while (i < n) {

    res[j][0] = nums[i++];
    res[j][1] = nums[i++];
    res[j][2] = nums[i++];

    if ((res[j][2] - res[j][0]) > k)
      return vector<vector<int>>(0);

    j++;
  }

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

    vector<vector<int>> res = divide_array(nums, k);
    for (vector<int> list : res) {
      for (int val : list)
        cout << val << " ";

      cout << endl;
    }
  }

  return 0;
}
