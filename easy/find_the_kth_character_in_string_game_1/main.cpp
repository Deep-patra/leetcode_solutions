#include <bits/stdc++.h>
using namespace std;

string s = "a";

char kth_character(int k) {

  if (s.length() < 500) {

    while (s.length() < 500) {
      string temp;

      for (char c : s)
        temp.push_back(c == 'z' ? 'a' : c + 1);

      s += temp;
    }
  }

  return s[k - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int k;
    cin >> k;

    char c = kth_character(k);
    cout << c << endl;
  }

  return 0;
}
