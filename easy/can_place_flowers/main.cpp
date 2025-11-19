#include <bits/stdc++.h>
using namespace std;

bool can_place_flowers(vector<int> &flower_bed, int n) {
  int l = flower_bed.size();

  if (n == 0)
    return 1;

  int i = 0;
  while (i < l && n > 0) {
    if (flower_bed[i] == 1) {
      i++;
      continue;
    }

    int left = max(i - 1, 0), right = min(l - 1, i + 1);

    if (flower_bed[left] == 0 && flower_bed[right] == 0) {
      flower_bed[i] = 1;
      n--;
    }

    i++;
  }

  if (n != 0)
    return 0;

  return 1;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> m >> n;

    vector<int> flower_bed(m);
    for (int i = 0; i < m; i++)
      cin >> flower_bed[i];

    bool res = can_place_flowers(flower_bed, n);
    cout << res << endl;
  }

  return 0;
}
