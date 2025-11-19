#include <bits/stdc++.h>
using namespace std;

int word_count(vector<string> &startWords, vector<string> &targetWords) {

  unordered_set<int> st;

  for (string s : startWords) {
    int mask = 0;

    for (char c : s)
      mask |= (1 << (c - 'a'));

    st.insert(mask);
  }

  int cnt = 0;
  for (string s : targetWords) {

    int mask = 0;

    for (char c : s)
      mask |= (1 << (c - 'a'));

    for (int i = 0; i < 26; i++) {
      if (mask & (1 << i)) {
        if (st.find(mask ^ (1 << i)) != st.end()) {
          cnt++;

          break;
        }
      }
    }
  }

  return cnt;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, m;
    cin >> n >> m;

    vector<string> start_words(n), target_words(m);
    for (int i = 0; i < n; i++)
      cin >> start_words[i];

    for (int i = 0; i < m; i++)
      cin >> target_words[i];

    int count = word_count(start_words, target_words);
    cout << count << endl;
  }

  return 0;
}
