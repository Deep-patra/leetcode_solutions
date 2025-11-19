#include <bits/stdc++.h>
using namespace std;

int max_product(vector<string> &words) {
  int n = words.size();

  vector<int> masks(n, 0);

  for (int i = 0; i < n; i++)
    for (char c : words[i])
      masks[i] |= (1 << (c - 'a'));

  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!(masks[i] & masks[j]))
        res = max(res, (int)words[i].length() * (int)words[j].length());
    }
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

    vector<string> words(n);
    for (int i = 0; i < n; i++)
      cin >> words[i];

    int max_prod = max_product(words);
    cout << max_prod << '\n';
  }

  return 0;
}
