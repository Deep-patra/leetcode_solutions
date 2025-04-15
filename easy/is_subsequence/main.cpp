#include <iostream>
#include <vector>
using namespace std;

int dp[101][10001];

// INFO: Runtime 4ms
bool is_subsequence(string s, string t) {
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= s.length(); i++) {
    for (int j = 1; j <= t.length(); j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        continue;
      }

      dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1]);
    }
  }

  return dp[s.length()][t.length()] == s.length();
}

// INFO: Runtime 0ms
bool is_subsequence_greedy(string s, string t) {
  int len = 0;

  int i = 0;
  while (i < t.length() && len < s.length()) {
    if (s[len] == t[i])
      len++;

    i++;
  }

  return len == s.length();
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s, t;
    cin >> s >> t;

    bool result = is_subsequence_greedy(s, t);
    cout << result << '\n';
  }

  return 0;
}
