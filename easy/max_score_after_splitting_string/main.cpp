#include <iostream>
using namespace std;

int max_score(string s) {
  int mx = 0;

  for (int i = 0; i < s.length() - 1; i++) {
    int left_mx = 0, right_mx = 0;

    // calculate the left
    int l = 0;
    while (l <= i) {
      if (s[l] == '0')
        left_mx++;

      l++;
    }

    // calculate the right
    int r = i + 1;
    while (r < s.length()) {
      if (s[r] == '1')
        right_mx++;

      r++;
    }

    mx = max(mx, left_mx + right_mx);
  }

  return mx;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string str;
    cin >> str;

    int result = max_score(str);

    cout << result << '\n';
  }

  return 0;
}
