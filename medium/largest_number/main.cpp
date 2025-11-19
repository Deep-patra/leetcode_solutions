#include <bits/stdc++.h>  
using namespace std;

string largest_number(vector<int> &nums) {

  int n = nums.size(), sum = 0, l = 0;

  vector<string> values(n);

  for (int i = 0; i < n; i ++) {
    values[i] = to_string(nums[i]);
    sum += nums[i];
    l += values[i].size();
  }

  if (sum == 0) return "0";

  auto comparator = [](string &a, string &b) -> bool {
    string f = a + b;
    string s = b + a;

    return f > s;
  };
 
  sort(values.begin(), values.end(), comparator);

  string res;
  res.reserve(l);

  for (string val : values)
    res += val;

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

    string res = largest_number(nums);
    cout << res << '\n';
  }

  return 0;
}
