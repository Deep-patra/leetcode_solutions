#include <bits/stdc++.h>
using namespace std;

bool is_scramble(string s1, string s2) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s1, s2;
    cin >> s1 >> s2;

    bool result = is_scramble(s1, s2);
    cout << result << '\n';
  }

  return 0;
}
