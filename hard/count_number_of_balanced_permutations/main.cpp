#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

unordered_set<string> st;
int char_freq[10];

void dfs(int n, int sum, int pos, int even, int odd, string &t, int &res) {
  if (pos == n && even == odd) {
    if (st.find(t) == st.end()) {
      res++;
      res %= MOD;

      st.insert(t);
    }

    return;
  }

  for (int i = 0; i < 10; i++) {

    if (char_freq[i] > 0) {

      if (pos & 1) {

        if (odd + i > (sum >> 1))
          return;

        char_freq[i]--;
        t.push_back(i + '0');

        dfs(n, sum, pos + 1, even, odd + i, t, res);

        char_freq[i]++;
        t.pop_back();
      }

      else {
        if (even + i > (sum >> 1))
          return;

        char_freq[i]--;
        t.push_back(i + '0');

        dfs(n, sum, pos + 1, even + i, odd, t, res);
        char_freq[i]++;
        t.pop_back();
      }
    }
  }

  return;
}

int count_number_of_balanced_permutations(string s) {

  // reset the unordered set and the frequency of the characters
  st.clear();
  memset(char_freq, 0, sizeof(char_freq));

  int sum = 0;
  for (char ch : s) {
    char_freq[ch - '0']++;

    sum += (ch - '0');
  }

  int res = 0;
  string t;

  if (sum & 1)
    return res;

  dfs(s.length(), sum, 0, 0, 0, t, res);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int res = count_number_of_balanced_permutations(s);
    cout << res << '\n';
  }

  return 0;
}
