#include <bits/stdc++.h>  
using namespace std;

int min_operations(vector<int> &nums) {
  nums.push_back(0);

  int n = nums.size(), ops = 0;

  stack<int> st;

  for (int i = 0; i < n; i ++) {
    if (nums[i] == 0) {
      ops += st.size();
      st = stack<int>();
      continue;
    }

    if (st.empty()) {
      st.push(nums[i]);
      continue;
    } 

    if (st.top() < nums[i]) 
      st.push(nums[i]);
    else {

      if (st.top() == nums[i])
        continue;

      while (!st.empty() && st.top() > nums[i]) {
        ops ++;
        st.pop();
      }

      if (st.empty() || (!st.empty() && st.top() != nums[i])) st.push(nums[i]);
    }
  } 

  return ops;
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

    int res = min_operations(nums);
    cout << res << endl;
  }

  return 0;
}
