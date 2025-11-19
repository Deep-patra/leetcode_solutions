#include <bits/stdc++.h>
using namespace std;

int num_of_unplaced_fruits(vector<int> &fruits, vector<int> &baskets) {
  int n = fruits.size(), placed = 0, j = 0;

  for (int val : fruits) {

    for (int j = 0; j < n; j++) {
      if (baskets[j] >= val) {
        baskets[j] = -1;
        placed++;

        break;
      }
    }
  }

  return fruits.size() - placed;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> fruits(n), baskets(n);

    for (int i = 0; i < n; i++)
      cin >> fruits[i];

    for (int i = 0; i < n; i++)
      cin >> baskets[i];

    int res = num_of_unplaced_fruits(fruits, baskets);
    cout << res << '\n';
  }

  return 0;
}
