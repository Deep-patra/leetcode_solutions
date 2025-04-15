#include <iostream>
#include <vector>
using namespace std;

int triangle_number(vector<int> &nums) { sort(nums.begin(), nums.end()); }

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len;
    cin >> len;

    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    int result = triangle_number(nums);
    cout << result << '\n';
  }

  return 0;
}
