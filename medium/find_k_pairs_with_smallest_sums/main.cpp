#include <bits/stdc++.h>
using namespace std;

// INFO: Solved But a Bit slow
vector<vector<int>> k_smallest_pairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
  int n = nums1.size();

  typedef pair<int, int> pi;
  typedef pair<int, pi> ppi;

  auto cmp = [](ppi a, ppi b) -> bool {
    if (a.first == b.first)
      return a.second.first == b.second.first
                 ? a.second.second < b.second.second
                 : a.second.first < b.second.first;

    return a.first < b.first;
  };

  priority_queue<ppi, vector<ppi>, decltype(cmp)> pq(cmp);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (pq.size() < k)
        pq.push({nums1[i] + nums2[j], make_pair(nums1[i], nums2[j])});
      else {
        if (pq.top().first > nums1[i] + nums2[j]) {
          pq.pop();
          pq.push({nums1[i] + nums2[j], make_pair(nums1[i], nums2[j])});
        }
      }
    }
  }

  vector<vector<int>> res;
  while (!pq.empty()) {
    res.push_back(vector<int>{pq.top().second.first, pq.top().second.second});
    pq.pop();
  }

  reverse(res.begin(), res.end());

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++)
      cin >> nums1[i];

    for (int i = 0; i < n; i++)
      cin >> nums2[i];

    vector<vector<int>> res = k_smallest_pairs(nums1, nums2, k);

    for (vector<int> v : res)
      cout << v[0] << " " << v[1] << " ";
    cout << endl;
  }

  return 0;
}
