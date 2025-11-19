#include <bits/stdc++.h>
using namespace std;

string shifting_letters(string s, vector<int> &shifts) {

  int n = shifts.size(), prev_shifts = 0;

  for (int i = n - 1; i >= 0; i--) {
    int d = ((s[i] - 'a') + shifts[i] + prev_shifts) % 26;
    s[i] = 'a' + d;

    if (i > 0)
      prev_shifts = (prev_shifts + shifts[i]) % 26;
  }

  return s;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    vector<int> shifts(s.length());
    for (int i = 0; i < shifts.size(); i++)
      cin >> shifts[i];

    string res = shifting_letters(s, shifts);
    cout << res << '\n';
  }

  return 0;
}
