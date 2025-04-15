#include <bits/stdc++.h>
using namespace std;

int my_atoi(string &s) {
  bool parse_digit = 0, is_negative = 0, is_trailing_zero = 1;
  string digit = "";

  for (int i = 0; i < s.length(); i++) {


    // if the + and - sign are present but no digit to follow them 
    // break the loop
    if ((s[i] == '-' || s[i] == '+') && i < s.length() - 1 && (s[i + 1] < '0' || s[i + 1] > '9'))
      break;

    // remove the leading whitespaces and positie signs
    if ((s[i] == ' ' || s[i] == '+') && !parse_digit)
      continue;
    
    if (s[i] == '-' && !parse_digit && i < s.length() - 1 && s[i + 1] >= '0' && s[i + 1] <= '9') {
      is_negative = 1;
      continue;
    }

    else if (s[i] >= '0' && s[i] <= '9') {
      parse_digit = 1;

      if (s[i] == '0' && is_trailing_zero)
        continue;

      is_trailing_zero = 0;

      digit.push_back(s[i]);

      if (digit.length() > 11)
        break;
    }

    // if any non-digit characer is encountered
    if (s[i] < '0' || s[i] > '9')
      break;
  }

  if (digit.length() == 0)
    return 0;

  long result = stol(digit) * (is_negative ? -1 : 1);

  if (result > INT_MAX)
    result = INT_MAX;

  else if (result < INT_MIN)
    result = INT_MIN;

  return (int)result;
}

int main() {
  int t;
  cin >> t;

  string str;
  getline(cin, str);

  while (t > 0) {
    t --;

    string s;
    getline(cin, s);

    int result = my_atoi(s);
    cout << result << '\n';
  }

  return 0;
}
