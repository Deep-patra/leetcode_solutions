#include <bits/stdc++.h>
using namespace std;

int longest_arith_sequence_length(vector<int> &nums) {}

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

    int result = longest_arith_sequence_length(nums);
    cout << result << '\n';
  }

  return 0;
}
