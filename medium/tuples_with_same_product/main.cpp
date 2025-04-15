#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int tuple_same_product(vector<int> &nums) {
  int n = nums.size();

  unordered_map<int, int> prod_frequency;

  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      prod_frequency[nums[i] * nums[j]]++;

  int result = 0;
  for (auto [product, frequency] : prod_frequency) {
    int pair_of_equal_product = (frequency - 1) * frequency / 2;

    result += 8 * pair_of_equal_product;
  }

  return result;
}

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

    int result = tuple_same_product(nums);
    cout << result << endl;
  }

  return 0;
}
