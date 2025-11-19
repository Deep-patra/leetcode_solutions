#include <bits/stdc++.h>
using namespace std;

int freq[(int)(1e6 + 1)];

vector<int> find_lonely(vector<int> &nums) {
  int n = nums.size();

  memset(freq, 0, sizeof(freq));

  for (int val : nums)
    freq[val]++;

  vector<int> res;
  for (int val : nums) {
    if (freq[val] > 1 || freq[val - 1] > 0 || freq[val + 1] > 0)
      continue;

    res.push_back(val);
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

    vector<int> res = find_lonely(nums);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
