#include <bits/stdc++.h>
using namespace std;

// INFO: Can be solved with Hare and Tortoise algorithm
int find_duplicate(vector<int> &nums) {
  
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

    int result = find_duplicate(nums);
    cout << result << '\n';
  }

  return 0;
}
