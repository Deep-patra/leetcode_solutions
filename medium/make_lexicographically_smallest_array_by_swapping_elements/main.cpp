#include <iostream>
#include <vector>
using namespace std;

/*



*/

// void divide_and_conquer(vector<int> &nums, int start, int end, int limit) {
//
//   if (start >= mid || mid >= end) return;
//
//   int mid = start + (end - start) / 2;
//   divide_and_conquer(nums, start, mid);
//   divide_and_conquer(nums, mid + 1, end);
//
//
// }

vector<int> lexicographically_smallest_array(vector<int> &nums, int limit) {
  vector<int> result = nums;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      int diff = nums[i] - nums[j];

      if (diff > 0 && diff <= limit)
        swap(result[i], result[j]);
    }
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, limit;
    cin >> m >> limit;

    vector<int> nums(m, 0);
    for (int i = 0; i < m; i++)
      cin >> nums[i];

    vector<int> result = lexicographically_smallest_array(nums, limit);

    for (int val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
