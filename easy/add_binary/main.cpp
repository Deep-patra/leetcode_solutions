#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string add_binary(string a, string b) {
  string result = "";
  char carry = '0';

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  // max length between the two
  int minimum = min(a.length(), b.length());

  int i = 0;
  while (i < minimum) {

    if (a[i] == '1' && b[i] == '1') {

      if (carry == '1')
        result = '1' + result;
      else
        result = '0' + result;

      carry = '1';
    } else if (a[i] == '1' || b[i] == '1') {

      if (carry == '1') {
        result = '0' + result;
        carry = '1';
      } else
        result = '1' + result;
    } else {

      if (carry == '1') {
        result = '1' + result;
        carry = '0';
      } else
        result = '0' + result;
    }

    i++;
  }

  int maximum = max(a.length(), b.length());

  if (i < maximum) {
    string max_string = a.length() > b.length() ? a : b;

    int j = minimum;
    while (j < maximum) {

      if (max_string[j] == '1') {

        if (carry == '1')
          result = '0' + result;
        else
          result = '1' + result;

      } else {

        if (carry == '1') {
          result = '1' + result;
          carry = '0';
        } else {
          result = '0' + result;
        }
      }

      j++;
    }
  }

  if (carry == '1')
    result = '1' + result;

  return result;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string a, b;
    cin >> a >> b;

    string result = add_binary(a, b);
    cout << result << '\n';
  }

  return 0;
}
