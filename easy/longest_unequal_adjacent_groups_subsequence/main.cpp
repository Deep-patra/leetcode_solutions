#include <bits/stdc++.h>
using namespace std;

vector<string> get_longest_subsequence(vector<string> &words,
                                       vector<int> &groups) {
  int n = words.size();

  vector<int> dp(n, 1), parent(n, -1);

  int longest = 1, longest_index = 0;

  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (groups[j] != groups[i]) {

        if (dp[i] < dp[j] + 1) {

          dp[i] = dp[j] + 1;

          if (longest <= dp[i]) {
            longest = dp[i];
            parent[i] = j;
            longest_index = i;

            break;
          }
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

    vector<string> res = get_longest_subsequence(words, groups);
    for (string s : res)
      cout << s << " ";

    cout << endl;
  }

  return 0;
}
