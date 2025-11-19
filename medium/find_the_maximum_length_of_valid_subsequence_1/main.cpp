#include <bits/stdc++.h>
using namespace std;

int maximum_length(vector<int> &nums) {
  int n = nums.size(), res = 0;

  pair<int, int> odd(0, 0), even(0, 0);

  if (nums[0] & 1) {
    odd.second = 1;
    even.second = 1;
  } else {
    odd.first = 1;
    even.first = 1;
  }

  for (int i = 1; i < n; i++) {

    if (nums[i] & 1) {
      even.second++;
      odd.second = odd.first + 1;
    } else {
      even.first++;
      odd.first = odd.second + 1;
    }
  }

  res = max({even.first, even.second, odd.first, odd.second});

  return res;
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

    int res = maximum_length(nums);
    cout << res << endl;
  }

  return 0;
}
