#include <bits/stdc++.h>
using namespace std;

bool check_if_subfolder(const vector<string> &f1, const vector<string> &f2) {
  for (int i = 0, l = min(f1.size(), f2.size()); i < l; i++) {
    if (f1[i] != f2[i])
      return 0;
  }

  return 1;
}

// INFO: Solved But is a lot SLOWER, Try a different Approach 
// TODO: Try to implement a efficient implementation using Trie Data structure
vector<string> remove_sub_folders(vector<string> &folder) {

  vector<vector<string>> pre(folder.size(), vector<string>(0));

  // preprocess all the strings
  for (int j = 0, size = folder.size(); j < size; j++) {
    string s = folder[j], f;

    for (int i = 1, l = s.length(); i < l; i++) {
      if (s[i] == '/') {
        pre[j].push_back(f);
        f = "";
      }

      if (s[i] != '/')
        f.push_back(s[i]);
    }

    pre[j].push_back(f);
  }

  int curr_idx = 0;
  vector<string> curr = pre[0], res;

  for (int i = 1, l = folder.size(); i < l; i++) {

    if (!check_if_subfolder(curr, pre[i])) {
      res.push_back(folder[curr_idx]);

      curr = pre[i];
      curr_idx = i;
    }
  }

  res.push_back(folder[curr_idx]);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<string> folder(n);
    for (int i = 0; i < n; i++)
      cin >> folder[i];

    vector<string> res = remove_sub_folders(folder);

    for (string s : res)
      cout << s << " ";

    cout << '\n';
  }

  return 0;
}
