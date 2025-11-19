#include <bits/stdc++.h>
using namespace std;

string sorted_string(string s) {
  vector<int> chars(26, 0);

  for (int i = 0; i < s.length(); i ++) 
    chars[s[i] - 'a'] ++;

  string res;

  for (int i = 0; i < 26; i ++) {
    while (chars[i] > 0) {
      res.push_back(i + 'a');
      chars[i] --;
    }
  }

  return res;
}

vector<vector<string>> group_anagrams(vector<string> &strs) {
  unordered_map<string, vector<string>> m;

  for (string s : strs) {
    string sorted = sorted_string(s);

    m[sorted].push_back(s);
  }

  vector<vector<string>> res;

  for (pair<string, vector<string>> p : m) 
    res.push_back(p.second);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i ++)
      cin >> strs[i];

    vector<vector<string>> result = group_anagrams(strs);

    for (vector<string> s : result) {
      for (string str : s)
        cout << str << " ";

      cout << endl;
    }
  }

  return 0;
}
