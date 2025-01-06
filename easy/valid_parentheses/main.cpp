#include <iostream>
#include <stack>
using namespace std;

bool is_valid(string s) {

  if (s.length() == 1)
    return false;

  stack<char> state;

  int round = 0, square = 0, curly = 0;

  for (int i = 0; i < s.length(); i++) {

    switch (s[i]) {
    case '(': {
      state.push('(');
      round++;
      break;
    }
    case ')': {
      if (state.empty() || state.top() != '(')
        return false;

      state.pop();
      round--;

      break;
    }
    case '{': {
      state.push('{');
      curly++;
      break;
    }
    case '}': {
      if (state.empty() || state.top() != '{')
        return false;

      state.pop();
      curly--;

      break;
    }
    case '[': {
      state.push('[');
      square++;
      break;
    }
    case ']': {
      if (state.empty() || state.top() != '[')
        return false;

      state.pop();
      square--;
      break;
    }
    }
  }

  if (!state.empty() || round != 0 || curly != 0 || square != 0)
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
