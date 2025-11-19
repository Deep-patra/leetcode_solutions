#include <bits/stdc++.h>
using namespace std;

// Using a Trie Data Structure
class WordDictionary {
public:
  WordDictionary() {}

  void addWord(string word) {}

  bool search(string word) {}
};

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    WordDictionary dict;

    vector<string> ops(n);
    for (int i = 0; i < n; i++)
      cin >> ops[i];

    for (int i = 0; i < n; i++) {

      if (ops[i] == "WordDictionary")
        cout << "null" << " ";

      if (ops[i] == "addWord") {
        string s;
        cin >> s;

        dict.addWord(s);
        cout << "null" << " ";
      }

      if (ops[i] == "search") {
        string s;
        cin >> s;

        bool res = dict.search(s);
        cout << (res ? "true" : "false") << " ";
      }
    }
  }

  return 0;
}
