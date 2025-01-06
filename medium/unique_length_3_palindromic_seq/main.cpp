#include <iostream>
#include <set>
#include <vector>
using namespace std;

// TODO: Optimize this algorithm
int count_palindromic_subsequence(string s) {

  set<string> result;
  vector<vector<int>> chars(26, vector<int>());

  // preprocess the string
  bool no_twice = true;
  for (int i = 0; i < s.length(); i++) {
    chars[s[i] - 'a'].push_back(i);

    if (chars[s[i] - 'a'].size() > 1)
      no_twice = false;
  }

  // no character is appearing twice, return 0
  if (no_twice)
    return result.size();

  for (int i = 0; i < chars.size(); i++) {

    if (chars[i].size() > 1) {
      int start = chars[i][0], end = chars[i][chars[i].size() - 1];

      for (int j = start + 1; j < end; j++) {
        string palindrome;

        palindrome += s[start];
        palindrome += s[j];
        palindrome += s[end];

        result.insert(palindrome);
      }
    }
  }

  return result.size();
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string s;
    cin >> s;

    int result = count_palindromic_subsequence(s);
    cout << result << '\n';
  }

  return 0;
}
