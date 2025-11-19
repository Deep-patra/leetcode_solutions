#include <bits/stdc++.h>
using namespace std;

vector<int> product_except_self(vector<int> &nums) {
  int n = nums.size();
  
  vector<int> res(n, 1);

  // compute prefix product
  for (int i = 0, prod = 1; i < n; i ++) {
    prod *= nums[i];
    res[i] = prod;
  }

  // compute suffix product
  for (int i = n - 1, prod = 1; i >= 0; i --) {
    int pre = i == 0 ? 1 : res[i - 1];
    res[i] = pre * prod;

    prod *= nums[i];
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

    vector<int> res = product_except_self(nums);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
