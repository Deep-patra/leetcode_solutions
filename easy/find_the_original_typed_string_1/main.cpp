#include <bits/stdc++.h>
using namespace std;

int possible_string_count(string word) {
  int n = word.length(), res = 1;

  char prev = word[0];
  for (int i = 1; i < n; i ++) {
    if (prev == word[i]) 
      res ++;

    prev = word[i];
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string word;
    cin >> word;

    int res = possible_string_count(word);
    cout << res << endl;
  }

  return 0;
}
