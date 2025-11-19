#include <bits/stdc++.h>  
using namespace std;

vector<int> get_sneaky_numbers(vector<int> &nums) {
  int n = nums.size();

  vector<int> res;
  for (int i = 0; i < n; i ++) {
    if (nums[i] != i) {

      int t = nums[i];

      while (nums[t] != -1 && nums[t] != t && t != i) {
        int temp = nums[t];
        nums[t] = t;

        t = temp;
      }

      if (nums[t] == -1) {
        nums[t] = t;
        nums[i] = -1;
      } else if (nums[t] == t) {
        nums[i] = -1;
        res.push_back(t);
      } else if (t == i)
        nums[i] = t;
    }
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

    vector<int> res = get_sneaky_numbers(nums);

    sort(res.begin(), res.end());

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
