#include <bits/stdc++.h>
using namespace std;

typedef struct Trie {

  vector<Trie *> upper, lower;
  bool end;

public:
  Trie() {
    upper = vector<Trie *>(26, nullptr);
    lower = vector<Trie *>(26, nullptr);

    end = 0;
  }
} Trie;

bool is_upper(char c) { return c >= 'A' && c <= 'Z'; }

bool is_lower(char c) { return c >= 'a' && c <= 'z'; }

char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
bool is_vowel(char c) {
  for (char t : vowels) {
    if (t == c)
      return 1;
  }

  return 0;
}

void add_word(Trie *root, string word) {

  for (char c : word) {

    if (is_upper(c)) {
      if (root->upper[c - 'A'] == nullptr)
        root->upper[c - 'A'] = new Trie();

      root = root->upper[c - 'A'];
    }

    else if (is_lower(c)) {
      if (root->lower[c - 'a'] == nullptr)
        root->lower[c - 'a'] = new Trie();

      root = root->lower[c - 'a'];
    }
  }

  root->end = 1;
}

string search_word(Trie *root, string word) {

  string res;

  typedef tuple<Trie *, int, string> s_type;

  stack<s_type> s;

  auto process_current_char = [&](Trie *root, char c, int i, string res) {
    if (is_upper(c) && root->upper[c - 'A'])
      s.push({root->upper[c - 'A'], i + 1, res + c});

    else if (is_lower(c) && root->lower[c - 'a'])
      s.push({root->lower[c - 'a'], i + 1, res + c});

    if (is_vowel(c)) {
      for (char v : vowels) {
        if (is_upper(v) && root->upper[v - 'A'])
          s.push({root->upper[v - 'A'], i + 1, res + v});

        if (is_lower(v) && root->lower[v - 'a'])
          s.push({root->lower[v - 'a'], i + 1, res + v});
      }
    } else {

      int d = is_upper(c) ? c - 'A' : c - 'a';
      if (root->upper[d])
        s.push({root->upper[d], i + 1, res + (char)('A' + d)});

      if (root->lower[d])
        s.push({root->lower[d], i + 1, res + (char)('a' + d)});
    }
  };

  process_current_char(root, word[0], 0, "");

  while (!s.empty()) {

    s_type top = s.top();
    s.pop();

    cout << get<2>(top) << endl;

    if (get<1>(top) == word.length() && get<0>(top)->end) {
      res = get<2>(top);
      break;
    }

    process_current_char(get<0>(top), word[get<1>(top)], get<1>(top),
                         get<2>(top));
  }

  return res;
}

vector<string> spell_checker(vector<string> &wordlist,
                             vector<string> &queries) {

  Trie *root = new Trie();

  for (string word : wordlist)
    add_word(root, word);

  vector<string> res;

  for (string q : queries)
    res.push_back(search_word(root, q));

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<string> wordlist(n), queries(m);
    for (int i = 0; i < n; i++)
      cin >> wordlist[i];

    for (int i = 0; i < m; i++)
      cin >> queries[i];

    vector<string> res = spell_checker(wordlist, queries);

    for (string s : res)
      cout << s << " ";

    cout << endl;
  }

  return 0;
}
