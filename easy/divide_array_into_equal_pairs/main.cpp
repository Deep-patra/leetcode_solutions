#include <bits/stdc++.h>
using namespace std;

int freq[ 501 ];

bool divide_array(vector<int> &nums) {
  memset(freq, 0, sizeof(freq));

  for (int val : nums)
    freq[val] ++;

  for (int f : freq)
    if (f & 1) return 0;

  return 1;
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

    bool result = divide_array(nums);
    cout << result << '\n';
  }

  return 0;
}
