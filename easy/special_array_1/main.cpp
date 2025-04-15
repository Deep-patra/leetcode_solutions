#include <iostream>
#include <vector>
using namespace std;

int is_array_special(vector<int> &nums) {
  if (nums.size() == 1) return true;

  for (int i = 1; i < nums.size(); i++)
    if (( nums[i - 1] & 1 ) == ( nums[i] & 1 ))
       return false;

  return true;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int len;
    cin >> len;

    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    int result = is_array_special(nums);
    cout << result << '\n';
  }

  return 0;
}
