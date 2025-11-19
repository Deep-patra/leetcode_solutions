#include <bits/stdc++.h>
using namespace std;

// Using Sliding Window Technique
string answer_string(string word, int numFriends) {
  int len = word.length(), l = len - (numFriends - 1);

  if (numFriends == 1) return word;

  string res = "";

  int i = 0;
  while ((i + l) < len) {
    string str = word.substr(i, min(l, len - i + 1));

    if (str > res)
      res = str;

    i ++;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string word;
    int num_friends;

    cin >> word >> num_friends;

    string res = answer_string(word, num_friends);

    cout << res << '\n';
  }

  return 0;
}
