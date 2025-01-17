#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permute(vector<int> &nums) {
  
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases --;

    int len;
    cin >> len;

    vector<int> nums(len);
    for (int i = 0; i < len; i++)
      cin >> nums[i];

    vector<vector<int>> result = permute(nums);

    for (vector<int> list : result)
      for (int val : list)
        cout << val << " ";

    cout << '\n';
  }

  return 0;
}
