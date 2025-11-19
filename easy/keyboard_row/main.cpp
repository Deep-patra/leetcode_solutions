#include <bits/stdc++.h>
using namespace std;

string keys[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

bool rows[3][26];
static bool initialized = 0;

vector<string> find_words(vector<string> &words) {

  if (!initialized) {

    memset(rows, 0, sizeof(rows));

    for (int i = 0; i < 3; i++) {
      for (char c : keys[i])
        rows[i][c - 'a'] = 1;
    }
  }

  initialized = 1;

  auto is_uppercase = [](char c) -> bool {
    if (c >= 'A' && c <= 'Z')
      return 1;

    return 0;
  };

  auto get_row = [&](char c) -> int {
    int d = is_uppercase(c) ? c - 'A' : c - 'a';

    if (rows[0][d])
      return 0;
    else if (rows[1][d])
      return 1;
    else
      return 2;
  };

  vector<string> res;

  for (string word : words) {

    bool same_row = 1;
    int row = get_row(word[0]);

    for (char c : word)
      if (get_row(c) != row) {
        same_row = 0;
        break;
      }

    if (same_row)
      res.push_back(word);
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

    vector<string> res = find_words(words);

    for (string w : res)
      cout << w << " ";

    cout << endl;
  }

  return 0;
}
