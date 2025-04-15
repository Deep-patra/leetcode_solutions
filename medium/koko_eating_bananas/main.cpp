#include <iostream>
#include <vector>
using namespace std;

int min_eating_speed(vector<int> &piles, int h) {
  int low = 0, high = INT_MIN;

  for (int i = 0; i < piles.size(); i++) 
    high = max(high, piles[i]);


  auto check_if_possible = [&](int val) -> bool {
    int res = 0;

    for (int i = 0; i < piles.size(); i++)
      res += (piles[i] % val == 0 ? (piles[i] / val) : (piles[i] / val) + 1);

    return res <= h;
  };

  int result = high;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (check_if_possible(mid)) {
      result = min(result, mid);
      high = mid - 1;
    }

    else
      low = mid + 1;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, h;
    cin >> n >> h;

    vector<int> piles(n, 0);
    for (int i = 0; i < n; i++)
      cin >> piles[i];

    int result = min_eating_speed(piles, h);
    cout << result << '\n';
  }

  return 0;
}
