#include <bits/stdc++.h>
using namespace std;

bool is_inter_leave(string s1, string s2, string s3) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    bool result = is_inter_leave(s1, s2, s3);
    cout << result << '\n';
  }

  return 0;
}
