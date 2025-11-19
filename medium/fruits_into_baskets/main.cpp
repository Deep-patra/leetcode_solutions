#include <bits/stdc++.h>
using namespace std;

// INFO: Can be Optimied using a improvised Kadane's Algorithm
int total_fruit(vector<int> &fruits) {
  int n = fruits.size(), res = 0;

  unordered_map<int, int> m;

  int l = 0, r = 0;
  while (r < n) {

    m[fruits[r]]++;

    if (m.size() > 2) {

      while (m.size() > 2 && l < n) {
        m[fruits[l]]--;

        if (m[fruits[l]] <= 0)
          m.erase(fruits[l]);
        l++;
      }
    }

    res = max(res, r - l + 1);
    r++;
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

    vector<int> fruits(n);
    for (int i = 0; i < n; i++)
      cin >> fruits[i];

    int res = total_fruit(fruits);
    cout << res << '\n';
  }

  return 0;
}
