#include <bits/stdc++.h>  
using namespace std;

vector<int> next_greater_elements(vector<int> &nums) {
  int n = nums.size();

  stack<int> s;

  for (int i = nums.size() - 1; i >= 0; i --) {
    
    while (!s.empty() && nums[i] >= nums[s.top()])
      s.pop();

    s.push(i);
  }

  vector<int> res(nums.size(), -1);
  for (int i = nums.size() - 1; i >= 0; i --) {
    while (!s.empty() && nums[i] >= nums[s.top()]) 
      s.pop();

    if (!s.empty()) res[i] = nums[s.top()];

    s.push(i);
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

    vector<int> res = next_greater_elements(nums);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
