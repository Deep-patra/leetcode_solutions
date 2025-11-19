#include <bits/stdc++.h>
using namespace std;

// Greedy Approach
vector<int> avoid_flood(vector<int> &rains) {
  int n = rains.size(), lake = -1;

  vector<int> res(n, -1);
  
  set<int> dry_idx;
  unordered_map<int, int> full_lakes;

  for (int i = 0; i < n; i++) {

    if (rains[i] == 0) {
      dry_idx.insert(i);
      continue;
    }

    if (full_lakes.count(rains[i])) {
      
      auto it = dry_idx.lower_bound(full_lakes[rains[i]]);

      // if cannot find an index to dry the lake, the lake will flood
      // return an empty array;
      if (it == dry_idx.end()) return vector<int>(0);

      res[*it] = rains[i];

      dry_idx.erase(it);
    }

    full_lakes[rains[i]] = i;
    lake = rains[i];
  }

  for (int i = 0; i < n; i ++) {
    if (rains[i] == 0 && res[i] == -1) 
      res[i] = lake;       
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> rains(n);
    for (int i = 0; i < n; i++)
      cin >> rains[i];

    vector<int> res = avoid_flood(rains);

    for (int val : res)
      cout << val << " ";
    cout << endl;
  }

  return 0;
}
