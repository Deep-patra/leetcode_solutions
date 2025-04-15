#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> successful_pairs(vector<int> &spells, vector<int> &potions,
                             long long success) {

  vector<int> result(spells.size(), 0);

  sort(potions.begin(), potions.end());

  for (int i = 0; i < spells.size(); i++) {
    int low = 0, high = potions.size() - 1, mid, res = 0;

    while (low <= high) {
      mid = low + (high - low) / 2;

      if (((ll)spells[i] * (ll)potions[mid]) >= success)
        high = mid - 1;

      else if (((ll)spells[i] * (ll)potions[mid]) < success)
        low = mid + 1;
    }

    result[i] += potions.size() - low;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    ll success;
    cin >> success;

    int m, n;
    cin >> m;

    vector<int> spells(m, 0);
    for (int i = 0; i < m; i++)
      cin >> spells[i];

    cin >> n;

    vector<int> potions(n, 0);
    for (int i = 0; i < n; i++)
      cin >> potions[i];

    vector<int> result = successful_pairs(spells, potions, success);
    for (int val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
