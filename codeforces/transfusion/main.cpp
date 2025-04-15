#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
  }

  return 0;
}
