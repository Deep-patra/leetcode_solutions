#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// TODO: Complete the Implementation
ll good_triplets(vector<int> &nums1, vector<int> &nums2) {
  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums1(n);
    for (int i = 0; i < n; i ++)
      cin >> nums1[i];

    int m;
    cin >> m;

    vector<int> nums2(m);
    for (int i = 0; i < m; i ++)
      cin >> nums2[i];

    ll result = good_triplets(nums1, nums2);
    cout << result << '\n';
  }

  return 0;
}
