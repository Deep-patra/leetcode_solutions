#include <bits/stdc++.h>
using namespace std;

// INFO: A bit slow, can be optimized by using a hash map instead of the array
int num_equiv_domino_pairs(vector<vector<int>> &dominoes) {

  int freq[10][10], result = 0;

  memset(freq, 0, sizeof(freq));

  for (vector<int> v : dominoes) {
    if (v[0] <= v[1])
      freq[v[0]][v[1]]++;
    else
      freq[v[1]][v[0]]++;
  }

  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      result += floor(freq[i][j] * (freq[i][j] - 1) / 2);
    }
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> dominoes(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
      cin >> dominoes[i][0] >> dominoes[i][1];

    int res = num_equiv_domino_pairs(dominoes);
    cout << res << '\n';
  }

  return 0;
}
