#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Complete the Implementation
// INFO: Hint: Use Matrix Multiplication and Matrix Exponentiation
int length_after_transformations(string s, int t, vector<int> &nums) {

  int res = 0;

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    int t;

    cin >> s >> t;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int res = length_after_transformations(s, t, nums);
    cout << res << '\n';
  }

  return 0;
}
