#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maximum_sum(vector<int> &nums) {
  unordered_map<int, vector<int>> m;

  int result = -1;

  for (int val : nums) {
    int temp = val;

    int sum = 0;
    while (temp != 0) {
      sum += temp % 10;
      temp /= 10;
    }

    bool inserted = false;
    if (m[sum].size() < 2) {
      m[sum].push_back(val);
      inserted = true;
    }

    if (m[sum].size() == 2) {

      if (!inserted) {
        if (m[sum][0] < m[sum][1])
          m[sum][0] = max(m[sum][0], val);
        else
          m[sum][1] = max(m[sum][1], val);
      }

      result = max(result, m[sum][0] + m[sum][1]);
    }
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = maximum_sum(nums);
    cout << result << endl;
  }

  return 0;
}
