#include <iostream>
using namespace std;

int range_bitwise_and(int left, int right) {

  if (left == 0 || right == 0)
    return 0;

  if (left == INT_MAX && right == INT_MAX)
    return left & right;

  int result = left;

  for (unsigned long long i = left + 1; i <= right && result != 0; i++)
    result &= i;

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int left, right;
    cin >> left >> right;

    int result = range_bitwise_and(left, right);
    cout << result << '\n';
  }

  return 0;
}
