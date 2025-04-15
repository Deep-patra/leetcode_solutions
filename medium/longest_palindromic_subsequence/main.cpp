#include <bits/stdc++.h>
using namespace std;

int longest_palindrome_subsequence(string s) {
  int len = s.length();

  int dp1[1001], dp2[1001];

  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));

  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= len; j++) {
      if (s[i - 1] == s[len - j])
        dp2[j] = dp1[j - 1] + 1;
      else
        dp2[j] = max(dp1[j], dp2[j - 1]);
    }

    for (int k = 0; k < 1001; k++) {
      dp1[k] = dp2[k];
      dp2[k] = 0;
    }
  }

  return dp1[len];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int result = longest_palindrome_subsequence(s);
    cout << result << '\n';
  }

  return 0;
}
