#include <bits/stdc++.h>
using namespace std;

string final_string(string s) {
  string res;
  
  int i_cnt = 0;
  for (char c : s) {
    if (c == 'i') {
      i_cnt ++;
      continue;
    }

    else {
      if (i_cnt > 0 && (i_cnt & 1)) 
        reverse(res.begin(), res.end());

      res.push_back(c);

      i_cnt = 0;
    }
  }

  if (i_cnt > 0 && (i_cnt & 1))
    reverse(res.begin(), res.end());

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    s = final_string(s);
    cout << s << endl;
  }

  return 0;
}
