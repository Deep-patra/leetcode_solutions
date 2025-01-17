#include <iostream>
#include <vector>
using namespace std;

// INFO: Time Limit exceeded
int xor_all_nums(vector<int> nums1, vector<int> nums2) {
  int result = 0;

  for (int i = 0; i < nums1.size(); i++) {
    for (int j = 0; j < nums2.size(); j++) {
      result ^= (nums1[i] ^ nums2[j]);
    }
  }

  return result;
}

int xor_all_nums_optimized(vector<int> nums1, vector<int> nums2) {
  int first = 0, second = 0;

  if (nums2.size() % 2 != 0) {
    for (int val : nums1)
      first ^= val;
  }

  if (nums1.size() % 2 != 0) {
    for (int val : nums2)
      second ^= val;
  }

  return first ^ second;
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len1, len2;
    cin >> len1;

    vector<int> nums1(len1, 0);
    for (int i = 0; i < len1; i++)
      cin >> nums1[i];

    cin >> len2;

    vector<int> nums2(len2, 0);
    for (int i = 0; i < len2; i++)
      cin >> nums2[i];

    // int result = xor_all_nums(nums1, nums2);
    int result = xor_all_nums_optimized(nums1, nums2);
    cout << result << '\n';
  }

  return 0;
}
