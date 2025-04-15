#include <bits/stdc++.h>
using namespace std;

static vector<string> m(3001);
static bool is_initialized = 0;

string int_to_roman(int num) {

  if (!is_initialized) {
    m[1] = "I";
    m[2] = "II";
    m[3] = "III";
    m[4] = "IV";
    m[5] = "V";
    m[6] = "VI";
    m[7] = "VII";
    m[8] = "VIII";
    m[9] = "IX";
    m[10] = "X";
    m[20] = "XX";
    m[30] = "XXX";
    m[40] = "XL";
    m[50] = "L";
    m[60] = "LX";
    m[70] = "LXX";
    m[80] = "LXXX";
    m[90] = "XC";
    m[100] = "C";
    m[200] = "CC";
    m[300] = "CCC";
    m[400] = "CD";
    m[500] = "D";
    m[600] = "DC";
    m[700] = "DCC";
    m[800] = "DCCC";
    m[900] = "CM";
    m[1000] = "M";
    m[2000] = "MM";
    m[3000] = "MMM";
  }

  is_initialized = true;

  string result = "";

  int temp = num, pow = 1;

  while (temp > 0) {
    int d = temp % 10;

    string roman = m[d * pow];

    reverse(roman.begin(), roman.end());

    result += roman;

    temp /= 10;
    pow *= 10;
  }

  reverse(result.begin(), result.end());

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int num;
    cin >> num;

    string result = int_to_roman(num);
    cout << result << '\n';
  }

  return 0;
}
