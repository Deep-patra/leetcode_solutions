#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<long long, pair<int, int>> item_type;

// INFO: Runtime 1ms
ll grid_game(vector<vector<int>> &grid) {
  int m = 2, n = grid[0].size();

  vector<vector<ll>> pref(m, vector<ll>(n, 0));

  pref[0][0] = (ll)grid[0][0];
  pref[1][0] = (ll)grid[1][0];

  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < n; j++) {
      pref[i][j] = pref[i][j - 1] + (ll)grid[i][j];
    }
  }

  ll second_min = LONG_LONG_MAX;
  for (int i = 0; i < n; i++) {
    ll first_max, second_max;

    if (i == 0) {
      first_max = grid[0][0] + pref[1][n - 1];
      second_max = pref[0][n - 1] - pref[0][i];
    } else if (i == n - 1) {
      first_max = pref[0][n - 1] + grid[1][n - 1];
      second_max = pref[1][i - 1];
    } else {
      first_max = pref[0][i] + (pref[1][n - 1] - pref[1][i - 1]);
      second_max = max((pref[0][n - 1] - pref[0][i]), pref[1][i - 1]);
    }

    if (first_max > second_max)
      second_min = min(second_min, second_max);
  }

  return second_min;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> grid(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    long long result = grid_game(grid);
    cout << result << '\n';
  }

  return 0;
}
