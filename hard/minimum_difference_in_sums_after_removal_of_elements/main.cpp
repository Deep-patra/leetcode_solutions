#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll minimum_difference(vector<int> &nums) {
  int n = nums.size();

  ll first_sum = 0, second_sum = 0;

  multiset<int> ms1, ms2;

  int m = n & 1 ? n / 2 : (n / 2) - 1;
  for (int i = 0; i <= m; i++) {
    first_sum += nums[i];
    ms1.insert(nums[i]);
  }

  for (int i = m + 1; i < n; i++) {
    second_sum += nums[i];
    ms2.insert(nums[i]);
  }

  int removed = 0, l = n / 3;
  while (removed < (l & (l ^ 1))) {

    // remove the maximum value from the first half of the set
    int mx = *(ms1.rbegin());
    first_sum -= mx;

    ms2.erase(mx);

    // remove the minimum value from the second half of the set
    int mn = *(ms2.begin());
    second_sum -= mn;

    ms1.erase(mn);

    removed += 2;
  }

  if (l & 1) {
    int mx = *(ms1.rbegin());
    first_sum -= mx;
  }

  return first_sum - second_sum;
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

    ll res = minimum_difference(nums);
    cout << res << endl;
  }

  return 0;
}
