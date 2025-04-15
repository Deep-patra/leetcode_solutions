#include <iostream>
#include <vector>
using namespace std;

int arrange_coins(int n) {
  int low = 1, high = n, result = 0;

  // using arithmetic progression
  // sum = n / 2 * (2 * first_term + (n - 1) * d)
  auto is_possible = [=](int mid, int n) -> bool {
    int sum = (mid * (1 + mid)) / 2;

    if (sum > n)
      return false;

    return true;
  };

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (is_possible(mid, n)) {
      low = mid + 1;
      result = max(result, mid);
    }

    else
      high = mid - 1;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    int result = arrange_coins(n);
    cout << result << '\n';
  }

  return 0;
}
