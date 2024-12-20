#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int max_chunks_to_make_sorted(vector<int> nums) {

  /**
    the logic of this problem is simple.

    - Keep increasing the partitions when there is a sorted elements.
    - Increase the paritions by 1, when there is a unsorted elements.
  **/

  // FIX: This algorithm doesn't work for [1, 2, 0, 3, 4]

  int partitions = 1;

  int max_num = INT_MIN; // maximum number in the patition
  int i = 1;

  while (i < nums.size()) {
    if (nums[i - 1] > nums[i]) {
      max_num = max(nums[i - 1], nums[i]);

      int j = i;
      while (j < nums.size() && max_num > nums[j])
        j++;

      i = j;
    } else {

      i++;
      partitions++;
    }
  }

  return partitions;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test_cases = 0;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++) {
    int length = -1;
    cin >> length;

    vector<int> nums;

    while (length > 0) {
      length--;

      int num = 0;
      cin >> num;

      nums.push_back(num);
    }

    int result = max_chunks_to_make_sorted(nums);
    cout << result << '\n';
  }

  return 0;
}
