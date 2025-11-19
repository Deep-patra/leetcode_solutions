#include <bits/stdc++.h>
using namespace std;

bool is_valid(string word) {

  if (word.size() < 3)
    return 0;

  bool vowels = 0, consonants = 0;
  for (char c : word) {

    bool valid = 0;

    if (c >= '0' && c <= '9')
      valid = 1;
    else if (c >= 'a' && c <= 'z') {
      valid = 1;

      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        vowels = 1;
      else
        consonants = 1;
    } else if (c >= 'A' && c <= 'Z') {
      valid = 1;

      if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        vowels = 1;

      else
        consonants = 1;
    }

    if (!valid)
      return 0;
  }

  if (!vowels || !consonants)
    return 0;

  return 1;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string word;
    cin >> word;

    bool res = is_valid(word);
    cout << res << endl;
  }

  return 0;
}
