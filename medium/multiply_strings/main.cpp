#include <bits/stdc++.h>  
using namespace std;

string add(string num1, string num2) {

  if (num1 == "" || num2 == "") return num1 == "" ? num2 : num1;

  int n1 = num1.length(), n2 = num2.length();
  int l = max(n1, n2);

  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());

  string res;

  int carry = 0;
  for (int i = 0; i < l; i ++) {
    int r = carry;

    if (i < n1) r += (num1[i] - '0');

    if (i < n2) r += (num2[i] - '0');

    carry = r / 10;
    res.push_back('0' + (r % 10));
  }

  if (carry > 0) res.push_back('0' + carry);

  reverse(res.begin(), res.end());
  return res;
}

string mul(string num1, char c) {

  if (c == '0') return "0";

  int n = num1.length();

  string res;

  int m = c - '0', carry = 0;

  for (int i = n - 1; i >= 0; i --) {
    int r = ((num1[i] - '0') * m) + carry;
    carry = r / 10;

    res.push_back('0' + (r % 10));
  }

  if (carry > 0) res.push_back('0' + carry);

  reverse(res.begin(), res.end());

  return res;
}

string multiply(string num1, string num2) {

  if (num1 == "0" || num2 == "0") return "0";
  
  int n2 = num2.length();
  reverse(num2.begin(), num2.end());

  string res;

  for (int i = 0; i < n2; i ++) {
    string n = mul(num1, num2[i]);

    int j = 1;
    while (j <= i) {
      n.push_back('0');
      j ++;
    }

    res = add(res, n); 
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    string num1, num2;
    cin >> num1 >> num2;

    string res = multiply(num1, num2);
    cout << res << '\n';
  }

  return 0;
}
