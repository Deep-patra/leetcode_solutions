#include <iostream>
#include <vector>
using namespace std;

bool isBadVersion(int version);

int first_bad_version(int n) {
  int low = 1, high = n, mid;

  while (low <= high) {
    mid = low + (high - low) / 2;

    int is_bad = isBadVersion(mid);

    if (!is_bad)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return low;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, bad;
    cin >> n >> bad;

    int result = first_bad_version(n);
  }

  return 0;
}
