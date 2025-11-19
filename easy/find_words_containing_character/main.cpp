#include <bits/stdc++.h>
using namespace std;

vector<int> find_words_containing(vector<string> &words, char x) {
  int n = words.size();

  vector<int> result;

  for (int i = 0; i < n; i++)
    for (char c : words[i])
      if (c == x) {
        result.push_back(i);
        break;
      }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    char c;

    cin >> n >> c;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
      cin >> words[i];
  }

  return 0;
}
