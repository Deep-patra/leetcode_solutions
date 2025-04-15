#include <iostream>
#include <vector>
using namespace std;

int sqrt(int n) {
  int low = 0, high = n, mid;

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (mid * mid == n)
      break;

    else if (mid * mid < n)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return mid * mid > n ? mid - 1 : mid;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int result = sqrt(n);
    cout << result << endl;
  }

  return 0;
}
