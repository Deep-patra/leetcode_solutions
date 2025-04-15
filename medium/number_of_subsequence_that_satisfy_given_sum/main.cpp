#include <iostream>
#include <vector>
using namespace std;

// TODO: Implement the algorithm
int num_subseq(vector<int> &nums, int target) {
  int mod = 10e9 + 7, result = 0;

  for (int i = 0; i < nums.size(); i++) {
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int target, n;
    cin >> target >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = num_subseq(nums, target);
    cout << result << endl;
  }

  return 0;
}
