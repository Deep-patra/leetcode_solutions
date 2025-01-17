#include <iostream>
#include <vector>
using namespace std;

string push_dominoes(string dominoes) {}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string dominoes;
    cin >> dominoes;

    string result = push_dominoes(dominoes);
    cout << result << '\n';
  }

  return 0;
}
