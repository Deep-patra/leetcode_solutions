#include <bits/stdc++.h>
using namespace std;

vector<int> find_anagrams(string s, string p) {
  int freq[26], curr_freq[26], n = s.length(), m = p.length();
  memset(freq, 0, sizeof(freq));
  memset(curr_freq, 0, sizeof(curr_freq));

  for (char c : p)
    freq[c - 'a']++;

  vector<int> res;

  for (int i = 0, j = 0; i < n; i++) {

    curr_freq[s[i] - 'a']++;

    if (i < (m - 1))
      continue;

    // check if the frequency matches
    int k = 0;
    while (k < 26 && curr_freq[k] == freq[k])
      k++;

    if (k == 26)
      res.push_back(j);

    curr_freq[s[j] - 'a']--;
    j++;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s, p;
    cin >> s >> p;

    vector<int> res = find_anagrams(s, p);
    for (int p : res)
      cout << p << " ";

    cout << endl;
  }

  return 0;
}
