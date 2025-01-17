#include <iostream>
#include <vector>
using namespace std;

int calculate_minimum_hp(vector<vector<int>> &dungeon) {}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> dungeon(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> dungeon[i][j];
      }
    }

    int result = calculate_minimum_hp(dungeon);
    cout << result << '\n';
  }

  return 0;
}
