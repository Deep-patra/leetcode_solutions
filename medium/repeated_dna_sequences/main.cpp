#include <bits/stdc++.h>  
using namespace std;

// TODO: Implement a Algorithm with hashing instead of set
vector<string> find_repeated_sequences(string s) {
  int l = s.length();

  unordered_map<string, int> m;

  vector<string> res;

  for (int i = 9; i < l; i ++) {
    string curr = s.substr((i + 1) - 10, 10);

    if (m.count(curr)) {

      if (m[curr] == 1)
        res.push_back(curr);

      m[curr] ++;

    } else 
      m[curr] = 1;
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

    vector<string> res = find_repeated_sequences(s);

    for (string str : res) 
      cout << str << " ";

    cout << endl;
  }

  return 0;
}
