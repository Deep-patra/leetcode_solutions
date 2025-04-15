#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int lcs(string word1, string word2) {

  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= word1.length(); i++) {
    for (int j = 1; j <= word2.length(); j++) {
      if (word1[i - 1] == word2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;

      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  return dp[word1.length()][word2.length()];
}

int min_distance(string word1, string word2) {
  int l = lcs(word1, word2);

  return (word1.length() + word2.length()) - (l << 1);
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string a, b;
    cin >> a >> b;

    int result = min_distance(a, b);
    cout << result << '\n';
  }

  return 0;
}
