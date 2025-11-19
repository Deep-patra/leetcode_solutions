#include <iostream>
#include <vector>
using namespace std;

bool is_possible(int val, const vector<int> &heaters, const vector<int> &houses) {
  int j = 0;
  for (int h : houses) {

    while (j < m && heaters[j] < (h - val))
      j++;

    if (j == m || heaters[j] > (h + val))
      return 0;
  }

  return 1;
}

// INFO: Dunno why but it's really slow than others, speed it up
// INFO: Got to 22 ms
int find_radius(vector<int> &houses, vector<int> &heaters) {
  sort(houses.begin(), houses.end());
  sort(heaters.begin(), heaters.end());

  int n = houses.size(), m = heaters.size();

  int l = 0, r = max(heaters[m - 1], houses[n - 1]), radius = r, mid = 0;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (is_possible(mid, heaters, houses)) {
      radius = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return radius;
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<int> houses(m, 0);
    for (int i = 0; i < m; i++)
      cin >> houses[i];

    vector<int> heaters(n, 0);
    for (int i = 0; i < n; i++)
      cin >> heaters[i];

    int result = find_radius(houses, heaters);
    cout << result << '\n';
  }

  return 0;
}
