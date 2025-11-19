#include <bits/stdc++.h>
using namespace std;

// TODO: Optimize this solution
// use a freq array instead of unordered_map
int longest_subsequence(vector<int> &arr, int difference) {
  int n = arr.size(), res = 1;

  unordered_map<int, int> m;

  for (int val : arr) {
    if (m.count(val - difference))
      m[val] = max(m[val], m[val - difference] + 1);

    else
      m[val] = max(m[val], 1);

    res = max(res, m[val]);
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, difference;
    cin >> n >> difference;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    int res = longest_subsequence(arr, difference);
    cout << res << endl;
  }

  return 0;
}
