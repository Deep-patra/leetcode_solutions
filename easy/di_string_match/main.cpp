#include <bits/stdc++.h>  
using namespace std;

vector<int> di_string_match(string s) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s;
    cin >> s;

    vector<int> res = di_string_match(s);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
