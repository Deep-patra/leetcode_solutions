#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

void fill_freq(string t, ui lower_freq[], ui upper_freq[]) {
  for (char ch : t) {
    if (ch >= 'a' && ch <= 'z')
      lower_freq[ch - 'a']++;

    else if (ch >= 'A' && ch <= 'Z')
      upper_freq[ch - 'A']++;
  }
}

bool check(ui freq_lower[], ui freq_upper[], ui pat_freq_lower[],
           ui pat_freq_upper[]) {
  for (int i = 0; i < 26; i++)
    if (freq_lower[i] < pat_freq_lower[i] || freq_upper[i] < pat_freq_upper[i])
      return false;

  return true;
}

bool is_present(char ch, ui freq_upper[], ui freq_lower[]) {
  if (ch >= 'a' && ch <= 'z')
    return freq_lower[ch - 'a'] > 0;
  else
    return freq_upper[ch - 'A'] > 0;
}

// INFO: Solved but really slow

string min_window(string s, string t) {
  int m = s.length(), n = t.length();

  if (m < n)
    return "";

  ui pat_freq_lower[26], pat_freq_upper[26];

  memset(pat_freq_lower, 0, sizeof(pat_freq_lower));
  memset(pat_freq_upper, 0, sizeof(pat_freq_upper));

  ui freq_lower[26], freq_upper[26];
  memset(freq_lower, 0, sizeof(freq_lower));
  memset(freq_upper, 0, sizeof(freq_upper));

  fill_freq(t, pat_freq_lower, pat_freq_upper);

  int i = 0, j = 0, start = -1, len = INT_MAX;

  if (s[0] >= 'a' && s[0] <= 'z')
    freq_lower[s[0] - 'a']++;
  else
    freq_upper[s[0] - 'A']++;

  while (j < m) {

    if ((j - i + 1) < n) {
      j++;

      if (s[j] >= 'a' && s[j] <= 'z')
        freq_lower[s[j] - 'a']++;
      else
        freq_upper[s[j] - 'A']++;

    }

    else if (check(freq_lower, freq_upper, pat_freq_lower, pat_freq_upper)) {
      int new_len = (j - i + 1);

      if (new_len < len) {
        start = i;
        len = new_len;
      }

      if (i == j && j == m - 1)
        break;

      else if (i == j && j < m - 1) {
        j++;

        if (s[j] >= 'a' && s[j] <= 'z')
          freq_lower[s[j] - 'a']++;
        else
          freq_upper[s[j] - 'A']++;
      }

      while (i < j) {

        if (s[i] >= 'a' && s[i] <= 'z')
          freq_lower[s[i] - 'a']--;
        else
          freq_upper[s[i] - 'A']--;

        i++;

        if (is_present(s[i], pat_freq_upper, pat_freq_lower))
          break;
      }
    }

    else {
      j++;

      if (s[j] >= 'a' && s[j] <= 'z')
        freq_lower[s[j] - 'a']++;
      else
        freq_upper[s[j] - 'A']++;
    }
  }

  return start != -1 ? s.substr(start, len) : "";
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s, t;
    cin >> s >> t;

    string result = min_window(s, t);
    cout << result << '\n';
  }

  return 0;
}
