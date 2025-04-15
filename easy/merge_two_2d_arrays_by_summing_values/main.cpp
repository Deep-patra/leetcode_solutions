#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge_arrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2) {
  int n = nums1.size(), m = nums2.size(), i = 0, j = 0;

  vector<vector<int>> result;

  while (i < n && j < m) {

    if (nums1[i][0] == nums2[j][0]) {
      result.push_back({ nums1[i][0], nums1[i][1] + nums2[j][1] });

      i ++;
      j ++;
    }

    else if (nums1[i][0] < nums2[j][0]) {
      result.push_back({ nums1[i][0], nums1[i][1] });

      i ++;
    }

    else {
      result.push_back({ nums2[j][0], nums2[j][1] });

      j ++;
    }
  }

  while (i < n) {
    result.push_back({ nums1[i][0], nums1[i][1] });
    i ++;
  }

  while (j < m) {
    result.push_back({ nums2[j][0], nums2[j][1] });
    j ++;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while ( t > 0) {
    t --;

    int n, m;

    cin >> n;

    vector<vector<int>> nums1(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
      cin >> nums1[i][0] >> nums1[i][1];

    cin >> m;

    vector<vector<int>> nums2(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++)
      cin >> nums2[i][0] >> nums2[i][1];

    vector<vector<int>> result = merge_arrays(nums1, nums2); 

    for (vector<int> list: result) {
      for (int val : list)
        cout << val << " ";

      cout << '\n';
    }
  }

  return 0;
}
