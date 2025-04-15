#include <bits/stdc++.h>
using namespace std;

// INFO: Use Merge Sort Approach for this problem
vector<int> count_smaller(vector<int> &nums) {
  list<int> l;

  for (int val : nums)
    l.push_back(val);

  // sort the list
  l.sort();

  vector<int> result(nums.size(), 0);

  for (int i = 0; i < nums.size(); i++) {
    int pos = lower_bound(l.begin(), l.end(), nums[i]);

    result[i] = pos;

    auto it = l.begin();
    advance(it, pos);

    l.erase(it);
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    vector<int> result = count_smaller(nums);

    for (int val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
