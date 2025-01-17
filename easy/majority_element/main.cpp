#include <iostream>
#include <map>
#include <vector>
using namespace std;

int majority_element(vector<int> &nums) {
  map<int, int> m;

  for (int i = 0; i < nums.size(); i++) {
    if (m.find(nums[i]) != m.end()) {
      m[nums[i]]++;
    } else
      m.insert(make_pair(nums[i], 1));
  }

  int result, maximum = 0;
  for (auto val : m) {
    if (maximum < val.second) {
      maximum = val.second;
      result = val.first;
    }
  }

  return result;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    int result = majority_element(nums);
    cout << result << '\n';
  }

  return 0;
}
