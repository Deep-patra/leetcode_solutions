#include <bits/stdc++.h>
using namespace std;

string simplify_path(string path) {

  int l = path.length();

  if (path[l - 1] != '/') {
    path.push_back('/');
    l++;
  }

  stack<string> st;

  string word = "";

  int i = 0;
  while (i < l) {

    if (path[i] == '/' && word.length() > 0) {

      if (word == "..") {
        if (!st.empty())
          st.pop();
      } else {
        if (word != ".") {
          st.push(word);
        }
      }

      word = "";
    }

    if (path[i] != '/')
      word.push_back(path[i]);

    i++;
  }

  string res;
  while (!st.empty()) {
    res = "/" + st.top() + res;
    st.pop();
  }

  if (res.length() == 0)
    res = "/";

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string path;
    cin >> path;

    string res = simplify_path(path);
    cout << res << '\n';
  }

  return 0;
}
