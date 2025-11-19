#include <bits/stdc++.h>  
using namespace std;

// TODO: Complete the implementation 
// HINT: It's a enumeration problem
int number_of_substrings(string s) {

  int len = s.length();

  vector<int> zeros(len, 0), ones(len, 0), zero_idx(len, -1);

  int zero_cnt = 0, one_cnt = 0;
  for (int i = 0; i < len; i ++) {
    char c = s[i];

    if (c == '0') 
      zero_cnt ++; 
    else 
      one_cnt ++;

    zeros[i] = zero_cnt;
    ones[i] = one_cnt;
  }

   

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    int res = number_of_substrings(s);
    cout << res << endl;
  }

  return 0;
}
