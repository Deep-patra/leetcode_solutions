#include <iostream>
#include <vector>
using namespace std;

int single_non_duplicate(vector<int> &nums) {
  
}

int main() {
  int t;
  cin >> t;

  while ( t > 0 ) {
    t --;

    int n;
    cin >> n;

    vector<int> nums (n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = single_non_duplicate(nums);
    cout << result << endl;
  }

  return 0;
}
