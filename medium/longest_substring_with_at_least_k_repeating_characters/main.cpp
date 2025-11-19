#include <bits/stdc++.h>
using namespace std;

// INFO: Getting Wrong Answer
// TODO: Implement the corrent solution
int longest_substring(string s, int k) {

  int n = s.length(), res = 0;

  vector<int> freq(26, 0), total(26, 0);

  for (char c : s)
    total[c - 'a']++;

  auto is_valid = [&]() -> bool {
    for (int f : freq)
      if (f != 0 && f < k)
        return 0;

    return 1;
  };

  freq[s[0] - 'a']++;

  int i = 0, j = 0;
  while (i < n && i >= j) {

    // if the current substring is valid
    // store the length
    if (is_valid())
      res = max(res, i - j + 1);

    // if the  front pointers are on the element which has
    // remaining frequency less than k
    if (i < n - 1 && total[s[i + 1] - 'a'] < k) {

      total[s[j] - 'a']--;
      freq[s[j] - 'a']--;

      if (i == j) {
        i++;
        j++;

        if (i < n)
          freq[s[i] - 'a']++;

        continue;
      }

      j++;
      continue;
    }

    i++;

    if (i < n)
      freq[s[i] - 'a']++;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int k;
    string s;

    cin >> s >> k;

    int res = longest_substring(s, k);
    cout << res << endl;
  }

  return 0;
}
