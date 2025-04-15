#include <iostream>
#include <vector>
using namespace std;

int dp[10001][26];

vector<vector<string>> group_anagrams(vector<string> &strs) {}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len;
    cin >> len;

    vector<string> strs;
    for (int i = 0; i < len; i++) {
      string s;
      cin >> s;

      strs.push_back(s);
    }

    vector<vector<string>> result = group_anagrams(strs);
  }

  return 0;
}
