#include <bits/stdc++.h>  
using namespace std;



string decode_string(string s) {
  int l = s.length();

  stack<string> st;
  stack<int> num_st;

  string res, num;

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    string res = decode_string(s);
    cout << res << '\n';
  }

  return 0;
}
