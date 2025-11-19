#include <bits/stdc++.h>
using namespace std;

vector<int> find_k_distant_indicies(vector<int> &nums, int key, int k) {
  int n = nums.size();

  vector<int> diff(n, 0), res;

  for (int i = 0; i < n; i++) {

    if (nums[i] == key) {
      int start = max(i - k, 0);

      diff[start] += 1;

      if (i + k + 1 < n)
        diff[i + k + 1] -= 1;
    }
  }

  int curr = 0;
  for (int i = 0; i < n; i ++) {
    curr += diff[i];

    if (curr > 0) res.push_back(i);
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, key, k;
    cin >> n >> key >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    vector<int> res = find_k_distant_indicies(nums, key, k);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
