#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sum_subarray_mins(vector<int> &arr) {
  int n = arr.size(), res = 0;

  stack<pair<int, int>> s;

  for (int i = 0; i < n; i++) {

    while (!s.empty() && arr[i] < arr[s.top().first])
      s.pop();

    int curr = 0;
    if (!s.empty())
      curr += s.top().second + ((i - s.top().first) * arr[i]);
    else
      curr = (i + 1) * arr[i];

    curr %= MOD;

    s.push({i, curr});

    res += curr;
    res %= MOD;
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

    int result = sum_subarray_mins(nums);
    cout << result << '\n';
  }

  return 0;
}
