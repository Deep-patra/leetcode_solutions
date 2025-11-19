#include <bits/stdc++.h>  
using namespace std;

int find_mex(unordered_multiset<int> s) {
  int i = 0;

  while (s.find(i) != s.end())
    i ++;

  return i;
}

int find_smallest_integer(vector<int> &nums, int value) {
  int n = nums.size();

  unordered_multiset<int> s(nums.begin(), nums.end());  

  int mex = find_mex(s);

  for (int val : nums) {

    // check if removing the number shifts the mex
    auto it = s.find(val);
    s.erase(it);

    int new_mex = find_mex(s);

    if (new_mex < mex) {
      s.insert(val);
      continue;
    }

    if (abs(mex - val) % value == 0) {
      s.insert(mex);
    } else {

      int v = val % value;

      v = v <= 0 ? v + value : v;

      while (s.find(v) != s.end())
        v += value;

      s.insert(v);

    }

    mex = find_mex(s);
  }

  return mex;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, value;
    cin >> n >> value;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int res = find_smallest_integer(nums, value);
    cout << res << endl;
  }

  return 0;
}
