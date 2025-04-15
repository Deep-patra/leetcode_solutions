#include <bits/stdc++.h>
using namespace std;

// using sliding window technique
int number_of_arithmetic_slices(vector<int> &nums) {
  if (nums.size() < 3) return 0;


}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = number_of_arithmetic_slices(nums);
    cout << result << '\n';
  }

  return 0;
}
