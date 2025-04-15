#include <bits/stdc++.h>
using namespace std;

// store the right most position of the characters
// present in the string
int right_pos[26];

vector<int> partition_labels(string s) {
  memset(right_pos, -1, sizeof(right_pos));

  for (int i = 0; i < s.length(); i++)
    right_pos[s[i] - 'a'] = max(right_pos[s[i] - 'a'], i);

  vector<int> result;

  int i = 0;
  while (i < s.length()) {

    int l = i, r = right_pos[s[i] - 'a'];

    while (l < r) {
      r = max(r, right_pos[s[l] - 'a']);
      l++;
    }

    result.push_back(r - i + 1);
    i = r + 1;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    vector<int> result = partition_labels(s);

    for (int val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
