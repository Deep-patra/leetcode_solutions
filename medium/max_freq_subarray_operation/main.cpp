#include <iostream>
#include <vector>
using namespace std;

int max_frequency(vector<int> nums, int k) {
  int result = 0;

  int l = 0, r = 0, num = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == k) {

    }


  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int k, m;
    cin >> k >> m;

    vector<int> nums(m, 0);
    for (int i = 0; i < m; i++)
      cin >> nums[i];

    int max_freq = max_frequency(nums, k);
    cout << max_freq << '\n';
  }

  return 0;
}
