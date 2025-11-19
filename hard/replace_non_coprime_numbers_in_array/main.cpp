#include <bits/stdc++.h>
using namespace std;

int __gcd(int a, int b) {
  if (b == 0)
    return a;

  if (a < b)
    swap(a, b);

  return __gcd(b, a % b);
}

vector<int> replace_non_coprimes(vector<int> &nums) {
  vector<int> res, temp(nums.begin(), nums.end());

  bool change = 1;

  while (change) {

    vector<int> temp_res;
    temp_res.push_back(temp[0]);

    change = 0;

    for (int i = 1, n = temp.size(); i < n; i++) {

      if (__gcd(temp[i], temp_res.back()) == 1) {

        temp_res.push_back(temp[i]);

      } else {
        change = 1;

        int lcm = temp_res.back(), j = i;
        while (j < n && __gcd(lcm, temp[j]) > 1) {
          lcm = (lcm * temp[j]) / __gcd(lcm, temp[j]);
          j++;
        }

        i = max(i, j - 1);
        temp_res[temp_res.size() - 1] = lcm;
      }
    }

    temp = vector<int>(temp_res.begin(), temp_res.end());
    res = vector<int>(temp_res.begin(), temp_res.end());
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

    vector<int> res = replace_non_coprimes(nums);

    for (int v : res)
      cout << v << " ";

    cout << endl;
  }

  return 0;
}
