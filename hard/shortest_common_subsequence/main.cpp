#include <bits/stdc++.h>
using namespace std;


// TODO: Complete the Implementation
string shortest_common_subsequence(string str1, string str2) {
  if (str1 == str2)
    return str1;

  string s = str1.length() > str2.length() ? str1 : str2;

  

  return s;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string str1, str2,
    cin >> str1 >> str2;

    string result = shortest_common_subsequence(str1, str2);
    cout << result << '\n';
  }

  return 0;
}
