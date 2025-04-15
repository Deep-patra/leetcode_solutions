#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sum_subarray_mins(vector<int> &arr) {
    
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int result = sum_subarray_mins(arr);
    cout << result << '\n';
  }

  return 0;
}
