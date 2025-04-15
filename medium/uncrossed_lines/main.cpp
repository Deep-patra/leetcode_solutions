#include <bits/stdc++.h>
using namespace std;

int max_uncrossed_lines(vector<int> &nums1, vector<int> &nums2) {}

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

    vector<int> nums2(n);
    for (int i = 0; i < m; i++)
      cin >> nums2[i];

    int result = max_uncrossed_lines(nums1, nums2);
    cout << result << '\n';
  }

  return 0;
}
