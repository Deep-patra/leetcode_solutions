#include <bits/stdc++.h>  
using namespace std;

typedef struct Trie {

public:
  Trie* child[26];
  bool end;
  vector<int> idx;

  Trie() {
    for (int i = 0; i < 26; i ++)
      child[i] = nullptr;

    end = 0;
  }
} Trie;

Trie* preprocess_words(vector<string> &words) {
  Trie root = new Trie();

  for (int i = 0; i < words.size(); i ++) {
    string s = words[i];
    
    Trie* curr = root;
    for (char c : s) {
      if (curr->child[c - 'a'] == nullptr)
        curr->child[c - 'a'] = new Trie();

      curr = curr->child[c - 'a'];
    }

    curr->end = 1;
    curr->idx.push_back(i);
  }  

  return root;
}



vector<int> find_substring(string s, vector<string> &words) {
  Trie* root = preprocess_words(words);

  vector<int> res;

  for (int i = 0; i < s.length(); i ++) {

  }


  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i ++)
      cin >> words[i];

    vector<Int> res = find_substring(s, words);
    cout << res << '\n';
  }

  return 0;
}
