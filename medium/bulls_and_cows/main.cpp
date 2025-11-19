#include <bits/stdc++.h>  
using namespace std;

string get_hint(string secret, string guess) {
  int secret_freq[10], guess_freq[10], bulls = 0, cows = 0;

  memset(secret_freq, 0, sizeof(secret_freq));
  memset(guess_freq, 0, sizeof(guess_freq));

  for (int i = 0, n = secret.length(); i < n; i ++) {
    if (secret[i] == guess[i]) {
      bulls ++;
      continue;
    }

    secret_freq[secret[i] - '0'] ++;
    guess_freq[guess[i] - '0'] ++;
  }

  for (int i = 0; i < 10; i ++) 
    cows += min(secret_freq[i], guess_freq[i]);


  return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string secret, guess;
    cin >> secret >> guess;

    string res = get_hint(secret, guess);
    cout << res << endl;
  }

  return 0;
}
