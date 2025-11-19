#include <bits/stdc++.h>
using namespace std;

// INFO: Trying out the n^2 formule
int max_removals(string source, string pattern, vector<int> &targetIndices) {
  int n = source.length();

  string temp = source;

  for (int idx : targetIndices)
    temp[idx] = '_';

  for (int i = 0; i < n; i ++) {
    
  }
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string source, pattern;
    cin >> source >> pattern;

    int n;
    cin >> n;

    vector<int> target_indices(n);
    for (int i = 0; i < n; i++)
      cin >> target_indices[i];

    int res = max_removals(source, pattern, target_indices);
    cout << res << '\n';
  }

  return 0;
}
