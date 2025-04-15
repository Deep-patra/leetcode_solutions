#include <bits/stdc++.h>
using namespace std;

int max_product(vector<int> &nums) {
  int result = INT_MIN, max_prod = 1, min_prod = 1;

  for (int num : nums) {

    int t = max_prod * num;

    max_prod = max({t, min_prod * num, num});
    min_prod = min({t, min_prod * num, num});

    result = max(result, max_prod);
  }

  return result;
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

    int result = max_product(nums);
    cout << result << '\n';
  }

  return 0;
}
