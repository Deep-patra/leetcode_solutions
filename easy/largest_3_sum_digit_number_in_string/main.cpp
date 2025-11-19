#include <bits/stdc++.h>
using namespace std;

string largest_good_integer(string num) {

  int l = num.length(), cnt = 1;

  string res;

  char prev = num[0];
  for (int i = 1; i < l; i++) {

    if (prev == num[i])
      cnt++;
    else
      cnt = 1;

    if (cnt == 3) {
      if (res.length() == 0 || (res.length() > 0 && res[0] < prev)) {
        res = "";
        res.push_back(prev);
        res.push_back(prev);
        res.push_back(prev);
      }

      cnt = 1;
    }

    prev = num[i];
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string num;
    cin >> num;

    string res = largest_good_integer(num);
    cout << res << '\n';
  }

  return 0;
}
