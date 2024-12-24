#include <iostream>
using namespace std;

// FIX: doesn't pass all the testcases
bool is_valid(string s) {
  int round_brac = 0, square_brac = 0, curly_brac = 0;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    switch (ch) {
    case '(': {
      round_brac++;
      break;
    }
    case ')': {
      if (round_brac == 0)
        return false;

      round_brac--;
      break;
    }
    case '[': {
      square_brac++;
      break;
    }
    case ']': {
      if (square_brac == 0)
        return false;

      square_brac--;
      break;
    }
    case '{': {
      curly_brac++;
      break;
    }
    case '}': {
      if (curly_brac == 0)
        return false;

      curly_brac--;
      break;
    }
    }
  }

  if (round_brac != 0 || square_brac != 0 || curly_brac != 0)
    return false;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string input;
    cin >> input;

    bool result = is_valid(input);

    cout << result << '\n';
  }

  return 0;
}
