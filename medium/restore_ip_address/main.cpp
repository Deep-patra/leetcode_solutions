#include <bits/stdc++.h>
using namespace std;

string dot = ".";

void generate_combinations(const string &s, set<string> &combs,
                           vector<string> &res, vector<string> &curr,
                           int idx = 0) {

  if (curr.size() > 4 || (idx > s.length() && curr.size() < 4))
    return;

  if (idx >= s.length() && curr.size() == 4) {
    string ip = curr[0] + dot + curr[1] + dot + curr[2] + dot + curr[3];

    if (combs.find(ip) == combs.end()) {
      combs.insert(ip);
      res.push_back(ip);
    }

    return;
  }

  string str;
  for (int i = idx; i < min((int)s.length(), idx + 3); i++) {

    if (s[i] == '0' && str.length() == 0) {
      curr.push_back("0");

      generate_combinations(s, combs, res, curr, i + 1);
      curr.pop_back();

      break;
    }

    str.push_back(s[i]);

    if (stoi(str) > 255)
      break;

    curr.push_back(str);

    generate_combinations(s, combs, res, curr, i + 1);

    curr.pop_back();
  }
}

vector<string> restore_ip_address(string s) {
  vector<string> res, curr;

  set<string> st;
  generate_combinations(s, st, res, curr);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    vector<string> res = restore_ip_address(s);

    for (string s : res)
      cout << s << " ";
    cout << endl;
  }

  return 0;
}
