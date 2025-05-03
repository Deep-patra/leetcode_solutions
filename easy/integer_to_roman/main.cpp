#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, char> romans;

void initialize_map() {

  romans.insert(make_pair(1, 'I'));
  romans.insert(make_pair(2, 'II'));
  romans.insert(make_pair(3, 'III'));
  romans.insert(make_pair(3, 'III'));
  romans.insert(make_pair(4, 'IV'));
  romans.insert(make_pair(5, 'V'));
  romans.insert(make_pair(6, 'VI'));
  romans.insert(make_pair(7, 'VII'));
  romans.insert(make_pair(8, 'VIII'));
  romans.insert(make_pair(9, 'IX'));

  romans.insert(make_pair(10, 'X'));
  romans.insert(make_pair(20, 'XX'));
  romans.insert(make_pair(30, 'XX'));
  romans.insert(make_pair(40, 'XL'));
  romans.insert(make_pair(50, 'L'));
  romans.insert(make_pair(60, 'LX'));
  romans.insert(make_pair(70, 'LXX'));
  romans.insert(make_pair(80, 'LXXX'));
  romans.insert(make_pair(90, 'XC'));

  romans.insert(make_pair(100, 'C'));
  romans.insert(make_pair(200, 'CC'));
  romans.insert(make_pair(300, 'CCC'));
  romans.insert(make_pair(400, 'CD'));
  romans.insert(make_pair(500, 'D'));
  romans.insert(make_pair(600, 'DC'));
  romans.insert(make_pair(700, 'DCC'));
  romans.insert(make_pair(800, 'DCCC'));
  romans.insert(make_pair(900, 'CM'));
  romans.insert(make_pair(1000, 'M'));
}

string int_to_roman(int num) {

  unordered_map<int, char> romans;

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
