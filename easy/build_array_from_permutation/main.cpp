#include <bits/stdc++.h>
using namespace std;

vector<int> build_array(vector<int> &nums) {
  int n = nums.size();

  vector<int> ans(n);

  for (int i = 0; i < n; i++)
    ans[i] = nums[nums[i]];

  return ans;
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

    vector<int> res = build_array(nums);
    for (int val : res)
      cout << val << ' ';

    cout << endl;
  }

  return 0;
}
