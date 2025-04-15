#include <iostream>
#include <vector>
using namespace std;

int count_partitions(vector<int> &nums) {
  vector<int> pref_sum(nums.size(), 0);

  pref_sum[0] = nums[0];

  for (int i = 1; i < nums.size(); i++)
    pref_sum[i] = pref_sum[i - 1] + nums[i];

  int partitions = 0;

  for (int i = 0; i < nums.size() - 1; i++)
    if (abs(pref_sum[i] - (pref_sum[nums.size() - 1] - pref_sum[i])) % 2 == 0)
      partitions++;

  return partitions;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m;
    cin >> m;

    vector<int> nums(m, 0);
    for (int i = 0; i < m; i++)
      cin >> nums[i];

    int result = count_partitions(nums);
    cout << result << '\n';
  }

  return 0;
}
