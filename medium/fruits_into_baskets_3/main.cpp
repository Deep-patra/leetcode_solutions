#include <bits/stdc++.h>
using namespace std;

// INFO: Got a TLE, Use Sqrt Decomposition for this problem
int num_of_unplaced_fruits(vector<int> &fruits, vector<int> &baskets) {
  int n = fruits.size(), unplaced = 0;

  typedef pair<int, int> pi;

  auto cmp = [](pi a, pi b) -> bool {
    return a.first < b.first;
  };

  multiset<pi, decltype(cmp)> s(cmp);

  for (int i = 0, j = 0; i < n; i++) {

    auto it = s.lower_bound({fruits[i], i});

    if (it != s.end()) {

      auto curr = it;
      while (it != s.end()) {
        auto p = it;

        if (p->second < curr->second)
          curr = p;

        it++;
      }

      s.erase(curr);

    } else {

      while (j < n && baskets[j] < fruits[i]) {
        s.insert({baskets[j], j});
        j++;
      }

      if (j >= n)
        unplaced++;
      else
        j++;
    }
  }

  return unplaced;
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
