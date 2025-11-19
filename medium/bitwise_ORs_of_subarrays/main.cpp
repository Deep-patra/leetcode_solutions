#include <bits/stdc++.h>
using namespace std;

int subarray_bitwise_ors(vector<int> &arr) {
  int n = arr.size(), res = 1;

  set<int> s, u;

  u.insert(arr[0]);

  for (int i = 1; i < n; i++) {

    set<int> m;

    for (int val : s) {
      m.insert(val | arr[i]);

      if (s.find(val | arr[i]) == s.end())
        res++;
    }

    if (s.find(arr[i - 1]) == s.end()) {
      m.insert(arr[i - 1] | arr[i]);

      if (u.find(arr[i - 1] | arr[i]) == u.end())
        res++;
    }

    if (u.find(arr[i]) == u.end()) {
      u.insert(arr[i]);
      res++;
    }

    s = m;
  }

  return res;
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

    int res = subarray_bitwise_ors(nums);
    cout << res << '\n';
  }

  return 0;
}
