#include <bits/stdc++.h>  
using namespace std;

int compress(vector<char> &chars) {
  int n = chars.size(), cnt = 1;

  vector<char> new_chars;

  auto append_len = [&](int num) {
    vector<char> digit;

    while (num > 0) {
      digit.push_back('0' + (num % 10));
      num /= 10;
    }

    for (int i = digit.size() - 1; i >= 0; i --) 
      new_chars.push_back(digit[i]);
  };

  char prev = chars[0];
  for (int i = 1; i < n; i ++) {

    if (prev == chars[i]) {
      cnt ++;
    } else {

      new_chars.push_back(prev);

      if (cnt > 1) 
        append_len(cnt);

      cnt = 1;
      prev = chars[i];
    }

  }

  new_chars.push_back(prev);
  if (cnt > 1)
    append_len(cnt);

  chars = new_chars;

  return chars.size();
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<char> chars(n);
    for (int i = 0; i < n; i ++) 
      cin >> chars[i];

    int res = compress(chars);
    cout << res << endl;
  }

  return 0;
}
