#include <bits/stdc++.h>
using namespace std;

int min_domino_rotations(vector<int> &tops, vector<int> &bottoms) {

  int freq[7], n = tops.size();

  memset(freq, 0, sizeof(freq));

  for (int i = 0; i < n; i++) {
    if (tops[i] == bottoms[i])
      freq[tops[i]]++;

    else {
      freq[tops[i]]++;
      freq[bottoms[i]]++;
    }
  }

  int max_freq = 0, max_val;

  for (int i = 1; i <= 6; i++) {
    if (freq[i] == n) {
      max_freq = n;
      max_val = i;
    }
  }

  if (max_freq < n)
    return -1;

  int top_min_ops = 0, bottoms_min_ops = 0;
  // minimum operations for the top
  for (int i = 0; i < n; i++) {
    if (max_val != tops[i])
      top_min_ops++;
  }

  // minimum operations for the bottom
  for (int i = 0; i < n; i++) {
    if (max_val != bottoms[i])
      bottoms_min_ops++;
  }

  return min(top_min_ops, bottoms_min_ops);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> tops(n), bottoms(n);
    for (int i = 0; i < n; i++)
      cin >> tops[i];

    for (int i = 0; i < n; i++)
      cin >> bottoms[i];

    int res = min_domino_rotations(tops, bottoms);
    cout << res << '\n';
  }

  return 0;
}
