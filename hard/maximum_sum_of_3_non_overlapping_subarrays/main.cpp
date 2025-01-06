#include <iostream>
using namespace std;

vector<int> max_sum_of_three_subarrays(vector<int> &nums, int k) {}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len, k;
    cin >> len >> k;

    vector<int> nums(len);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    auto result = max_sum_of_three_subarrays(nums, k);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
