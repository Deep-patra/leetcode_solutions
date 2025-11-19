#include <bits/stdc++.h>
using namespace std;

int min_cost(string colors, vector<int> &needed_time) {
  int n = needed_time.size(), res = 0;

  colors.push_back('$');
  needed_time.push_back(0);

  char prev = colors[0];
  int max_time = needed_time[0], curr_sum = needed_time[0];
  for (int i = 1, len = colors.length(); i < len; i++) {
    if (colors[i] == prev) {

      curr_sum += needed_time[i];
      max_time = max(max_time, needed_time[i]);

    } else {

      res += curr_sum - max_time;
      curr_sum = needed_time[i];
      max_time = needed_time[i];
    }

    prev = colors[i];
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string colors;
    cin >> colors;

    int n;
    cin >> n;

    vector<int> needed_time(n);
    for (int i = 0; i < n; i++)
      cin >> needed_time[i];

    int res = min_cost(colors, needed_time);
    cout << res << endl;
  }

  return 0;
}
