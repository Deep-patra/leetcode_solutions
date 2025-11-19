#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// TODO: Complete the Implementation
ll min_sum(vector<int> &nums1, vector<int> &nums2) {
  ll zeros1 = 0, zeros2 = 0, sum1 = 0, sum2 = 0;

  for (int i = 0; i < nums1.size(); i++) {
    if (nums1[i] == 0)
      zeros1++;

    sum1 += nums1[i];
  }

  for (int i = 0; i < nums2.size(); i++) {
    if (nums2[i] == 0)
      zeros2++;

    sum2 += nums2[i];
  }

  if (sum1 == sum2 && zeros1 == 0 && zeros2 == 0)
    return sum1;

  if (sum1 < sum2) {

    int diff = (sum2 + zeros2) - sum1;

    if (diff < zeros1)
      return sum2 + zeros1;

    else
      return sum2 + zeros2;

  } else {

    int diff = (sum1 + zeros1) - sum2;

    if (diff < zeros2)
      return sum1 + zeros2;

    else
      return sum1 + zeros1;
  }
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n;

    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
      cin >> nums1[i];

    cin >> m;

    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
      cin >> nums2[i];

    ll res = min_sum(nums1, nums2);
    cout << res << '\n';
  }

  return 0;
}
