#include <bits/stdc++.h>
using namespace std;

int hamming_distance(string &s1, string &s2) {
  int len1 = s1.length(), len2 = s2.length();

  if (len1 != len2)
    return 0;

  int d = 0;
  for (int i = 0; i < len1; i++) {
    if (s1[i] != s2[i])
      d++;
  }

  return d;
}

vector<string> get_words_in_longest_subsequence(vector<string> &words,
                                                vector<int> &groups) {

  int n = words.size();

  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int d = hamming_distance(words[i], words[j]);

      dp[i][j] = dp[j][i] = d;
    }
  }

  vector<int> len(n, 1), parent(n, -1);
  int longest_index = 0, longest = 1;

  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (dp[i][j] == 1 && groups[i] != groups[j]) {

        if (len[i] < (1 + len[j])) {
          len[i] = 1 + len[j];

          if (longest <= len[i]) {
            longest = len[i];
            longest_index = i;
          }

          parent[i] = j;
        }
      }
    }
  }

  vector<string> res;
  for (int i = longest_index; i != -1; i = parent[i])
    res.push_back(words[i]);

  reverse(res.begin(), res.end());

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

    vector<int> groups(n);
    for (int i = 0; i < n; i++)
      cin >> groups[i];

    vector<string> res = get_words_in_longest_subsequence(words, groups);
    for (string s : res)
      cout << s << " ";

    cout << endl;
  }

  return 0;
}
