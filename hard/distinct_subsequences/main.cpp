#include <bits/stdc++.h>
using namespace std;

int num_distinct(string s, string t) {
  int dp1[1001], dp2[1001], len1 = s.length(), len2 = t.length();

  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));

  for (int i = 1; i <= len1; i++)
    dp1[i] = t[0] == s[i - 1] ? dp1[i - 1] + 1 : dp1[i - 1];

  if (dp1[len1] == 0)
    return 0;

  for (int i = 2; i <= len2; i++) {
    for (int j = 1; j <= len1; j++) {
      if (s[j - 1] == t[i - 1])
        dp2[j] = dp2[j - 1] + dp1[j - 1];
      else
        dp2[j] = dp2[j - 1];
    }

    if (dp2[len1] == 0)
      return 0;

    for (int k = 0; k <= len1; k++) {
      dp1[k] = dp2[k];
      dp2[k] = 0;
    }
  }

  return dp1[len1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s, t;
    cin >> s >> t;

    int result = num_distinct(s, t);
    cout << result << '\n';
  }

  return 0;
}
