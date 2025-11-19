#include <bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int> &nums) {
  int n = nums.size();

  int j = 1, prev = nums[0], cnt = 1;
  for (int i = 1; i < n; i++) {

    if (nums[i] == prev && cnt == 2)
      continue;

    if (nums[i] == prev && cnt < 2) {
      cnt++;

      nums[j] = nums[i];
      j++;

      continue;
    }

    cnt = 1;
    prev = nums[i];
    nums[j] = nums[i];
    j++;
  }

  return j;
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

    int res = remove_duplicates(nums);
    cout << res << '\n';

    for (int val : nums)
      cout << val << " ";
    cout << endl;
  }

  return 0;
}
