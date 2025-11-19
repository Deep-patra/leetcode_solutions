#include <bits/stdc++.h>
using namespace std;

string digits[10] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};
int digit_freq[10][26];
bool initialized = 0;

void initialize_table() {

  memset(digit_freq, 0, sizeof(digit_freq));

  for (int i = 0; i < 10; i++)
    for (char c : digits[i])
      digit_freq[i][c - 'a']++;

  initialized = 1;
}

// TODO: Write a correct implementation
string original_digits(string s) {

  if (!initialized)
    initialize_table();

  int freq[26];
  memset(freq, 0, sizeof(freq));

  for (char c : s)
    freq[c - 'a']++;

  auto if_present = [&](int i) -> bool {
    bool is_present = 1;

    for (int k = 0; k < 26; k++) {
      if (freq[k] < digit_freq[i][k]) {
        is_present = 0;
        break;
      }
    }

    return is_present;
  };

  string res;
  for (int i = 0; i < 10; i++) {
    while (if_present(i)) {

      res.push_back('0' + i);

      for (int k = 0; k < 26; k++)
        freq[k] -= digit_freq[i][k];
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    string res = original_digits(s);
    cout << res << endl;
  }

  return 0;
}
