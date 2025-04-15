#include <iostream>
using namespace std;

int num_distinct(string s, string t) {}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s, t;
    cin >> s >> t;

    int result = num_distinct(s, t);
    cout << result << '\n';
  }

  return 0;
}
