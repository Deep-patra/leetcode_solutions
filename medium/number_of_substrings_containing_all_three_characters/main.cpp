#include <bits/stdc++.h>
using namespace std;

int number_of_substrings(string s) {

  int a = 0, b = 0, c = 0, n = s.length();
  int start = 0, end = -1, res = 0;

  auto is_valid = [&]() -> bool {
    return (a > 0 && b > 0 && c > 0);
  };

  while (end < n) {

    if (is_valid()) {
      res += (n - end);

      if (s[start] == 'a') a --;
      else if (s[start] == 'b') b --;
      else c --;

      start ++;

    } else {
      end ++;

      if (end >= n) break;

      if (s[end] == 'a') a ++;
      else if (s[end] == 'b') b ++;
      else c ++;

    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    int result = number_of_substrings(s);

    cout << result << '\n';
  }

  return 0;
}
