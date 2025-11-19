#include <bits/stdc++.h>  
using namespace std;

// TODO: Complete the Implementation
string find_lex_smallest_string(string s, int a, int b) {
  int l = s.length();

  
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    int a, b;

    cin >> s >> a >> b;

    string res = find_lex_smallest_string(s, a, b);
    cout << res << endl;
  }

  return 0;
}
