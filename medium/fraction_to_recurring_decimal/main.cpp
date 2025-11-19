#include <bits/stdc++.h>  
using namespace std;

string fraction_to_decimal(int numerator, int denominator) {

  if (numerator == 0) return "0";

  string res, integer, decimal;

  typedef long long ll;

  bool neg = 0;
  if (numerator < 0 && denominator > 0 || (numerator > 0 && denominator < 0))
    neg = 1;

  ll num = abs(numerator), den = abs(denominator);

  if (num >= den) {
    integer = to_string(num / den);
    num = num % den;
  } else 
    integer = "0";

  if (neg) integer = '-' + integer; 

  unordered_map<int, int> m;
  while (num != 0 && m.find(num) == m.end()) {
    m[num] = decimal.length();

    if (num < den)
      num *= 10;

    while (num < den) {
      num *= 10;
      decimal.push_back('0');
    }
    
    decimal += to_string(num / den);
    num %= den;
  }

  if (num == 0) return integer + "." + decimal;

  string new_decimal;
  for (int i = 0; i < decimal.length(); i ++) {
    if (i == m[num]) new_decimal.push_back('(');
    new_decimal.push_back(decimal[i]);
  }

  return integer + "." + new_decimal + ")";
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int num, den;
    cin >> num >> den;

    string res = fraction_to_decimal(num, den);
    cout << res << endl;
  }

  return 0;
}
