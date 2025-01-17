#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(string s, int start, int end) {
  for (int i = start; i <= end; i++)
    if (s[start] != s[end - 1 - i])
      return false;

  return true;
}

// TODO: Complete the implementation
vector<vector<string>> partition_recurse(string s, int start = 0) {
  vector<vector<string>> result;

  for (int i = start; i < s.length(); i++) {
    if (is_palindrome(s, 0, i)) {

      vector<vector<string>> res = partition_recurse(s, i + 1);

      for (vector<string> list : res) {
        vector<string> temp;

        temp.push_back(s) for (string val : list)
      }
    }
  }

  return result;
}

vector<vector<string>> partition(string s) {}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string word;
    cin >> word;

    vector<vector<string>> result = partition(word);

    // print the result
    for (vector<string> val : result) {
      cout << val.size() << '\n';

      for (string s : val)
        cout << s << " ";

      cout << '\n';
    }
  }

  return 0;
}
