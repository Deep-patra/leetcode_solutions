#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int count_winning_sequences(string s) {
  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    int result = count_winning_sequences(s);
    cout << result << '\n';
  }

  return 0;
}
