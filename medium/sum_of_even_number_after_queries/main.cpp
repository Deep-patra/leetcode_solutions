#include <bits/stdc++.h>  
using namespace std;

vector<int> sum_even_after_queries(vector<int> &nums, vector<vector<int>> &queries) {

  int sum = 0;

  for (int val : nums)
    if (!(val & 1))
      sum += val;

  vector<int> res;
  for (auto &q : queries) {
    
    if (!(nums[q[1]] & 1)) 
      sum -= nums[q[1]];

    nums[q[1]] += q[0];

    if (!(nums[q[1]] & 1))
      sum += nums[q[1]];

    res.push_back(sum);
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

    int m;
    cin >> m;

    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i ++)
      cin >> queries[i][0] >> queries[i][1];


    vector<int> res = sum_even_after_queries(nums, queries);
    for (int val : res)
      cout << val << ' ';

    cout << endl;
  }

  return 0;
}
