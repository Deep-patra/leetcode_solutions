#include <bits/stdc++.h>  
using namespace std;

bool does_alice_win(string s) {
  int vowels = 0;

  for (char c : s) 
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowels ++;

  return vowels == 0 ? 0 : 1;
} 

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    bool res = does_alice_win(s);
    cout << res << endl;
  }

  return 0;
}
