#include <bits/stdc++.h>
using namespace std;

int dp1[1001];
int dp2[1001];

int find_length(vector<int> &nums1, vector<int> &nums2) {

  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));

  int result = 0;
  for (int i = 1; i <= nums1.size(); i++) {
    for (int j = 1; j <= nums2.size(); j++) {
      if (nums1[i - 1] == nums2[j - 1])
        dp2[j] = dp1[j - 1] + 1;

      result = max(result, dp2[j]);
    }

    for (int k = 0; k <= nums2.size(); k++)
      dp1[k] = dp2[k];
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

    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
      cin >> nums1[i];

    int m;
    cin >> m;

    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
      cin >> nums2[i];

    int result = find_length(nums1, nums2);
    cout << result << '\n';
  }

  return 0;
}
