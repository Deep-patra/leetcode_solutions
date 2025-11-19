#include <bits/stdc++.h>
using namespace std;

// INFO: Complete the Imlementation
int minimum_deletions(string s, int k) {
  vector<int> freq(26, 0);

  for (char c : s)
    freq[c - 'a'] ++;

  sort(freq.begin(), freq.end());

  
}

int main() {
  int t;
  cin >> t;

  string s;
  int k;

  cin >> s >> k;

  int res = minimum_deletions(s, k);
  cout << res << '\n';

  return 0;
}
