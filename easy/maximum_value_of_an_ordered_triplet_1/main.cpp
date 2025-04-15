#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maximum_triplet_value(vector<int> &nums) {
  ll result = LONG_MIN;

  for (int i = 0; i < nums.size() - 2; i ++) {
    for (int j = i + 1; j < nums.size() - 1; j ++) {
      for (int k = j + 1; k < nums.size(); k ++) {
        result = max(result, (nums[i] - nums[j]) * nums[k]);
      }
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
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    ll result = maximum_triplet_value(nums);
    cout << result << '\n';
  }

  return 0;
}
