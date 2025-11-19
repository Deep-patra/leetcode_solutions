#include <bits/stdc++.h>
using namespace std;

vector<string> divide_string(string s, int k, char fill) {
  int n = s.length();

  vector<string> res;

  for (int i = 0; i < n; i += k) {
    string a;

    int j = i, cnt = 0;
    while (j < n && cnt < k) {
      a.push_back(s[j]);

      cnt ++;
      j ++;
    }

    while (a.length() < k) 
      a.push_back(fill);


    res.push_back(std::move(a));
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    int k;
    char fill;

    cin >> s >> k >> fill;

    vector<string> res = divide_string(s, k, fill);

    for (string s: res)
      cout << s << " ";
    cout << endl;
  }

  return 0;
}
