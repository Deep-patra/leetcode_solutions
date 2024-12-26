#include <iostream>
#include <unordered_map>
using namespace std;

string int_to_roman(int num) {

  unordered_map<int, char> romans;

  romans.insert(make_pair(1, 'I'));
  romans.insert(make_pair(5, 'V'));
  romans.insert(make_pair(10, 'X'));
  romans.insert(make_pair(50, 'L'));
  romans.insert(make_pair(100, 'C'));
  romans.insert(make_pair(500, 'D'));
  romans.insert(make_pair(1000, 'M'));

  string result;

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int num;
    cin >> num;

    string result = int_to_roman(num);

    cout << result << '\n';
  }

  return 0;
}
