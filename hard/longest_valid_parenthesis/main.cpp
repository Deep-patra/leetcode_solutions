#include <bits/stdc++.h>
using namespace std;

int find_longest(string s) {
  int n = s.length(), result = 0, open = 0, close = 0;

  int i = 0, j = 0;

  while (j < n) {
    if (s[j] == '(') open ++;
    else close ++;

    if (open < close) {
      if (j + 1 < n) i = j = j + 1;
      else break;
    }

    else if (open > close) {
      j ++;            
    }

    else if (open == close) {
      result = max(result, (j - i + 1));
      j ++;
    }

  }

  return result;
}

int longest_valid_parenthesis(string s) {
  int r1 = find_longest(s);

  reverse(s.begin(), s.end());

  int r2 = find_longest(s);

  return max(r1, r2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string input;
    cin >> input;

    bool result = longest_valid_parenthesis(input);

    cout << result << '\n';
  }

  return 0;
}
