#include <bits/stdc++.h>
using namespace std;

int triangle_number(vector<int> &nums) {
  int n = nums.size(), res = 0;

  sort(nums.begin(), nums.end());

  auto bs = [&](int l, int r, int val) -> int {
    int pos = l;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (val > nums[mid]) {
        l = mid + 1;
        pos = mid;
      } else
        r = mid - 1;
    }

    return pos;
  };

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int s = nums[i] + nums[j];

      int r = bs(j, n - 1, s);

      res += (r - j);
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len;
    cin >> len;

    vector<int> nums(len);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    int result = triangle_number(nums);
    cout << result << '\n';
  }

  return 0;
}
