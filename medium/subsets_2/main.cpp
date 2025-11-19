#include <bits/stdc++.h>  
using namespace std;

// TODO: Implement a optimized solution
vector<vector<int>> subsets(vector<int> &nums) {

  int n = nums.size();

  set<string> s;

  vector<vector<int>> res;
  
  for (int mask = 0; mask < (1 << n); mask ++) {
    
    vector<int> curr;

    for (int j = 0; j < n; j ++) 
      if (mask & (1 << j)) curr.push_back(nums[j]);

    sort(curr.begin(), curr.end());

    string str;
    for(int val : curr)
      str += to_string(val);

    if (s.find(str) != s.end())
      continue;

    res.push_back(curr);
    s.insert(str);
  }

  return res;
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

    vector<vector<int>> res = subsets(nums);

    for (vector<int> v : res) {
      for (int val : v)
        cout << val << " ";

      cout << endl;
    }
  }

  return 0;
}
