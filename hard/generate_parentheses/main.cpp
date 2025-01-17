#include <assert.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// FIX: Wrong Implementation (Wrong Answer)
set<string> generate_parentheses_recurse(int n) {
  set<string> result;

  if (n == 1) {
    result.insert("()");
    return result;
  }

  set<string> prev_result = generate_parentheses_recurse(n - 1);

  for (auto val : prev_result) {
    result.insert("()" + val);
    result.insert("(" + val + ")");
    result.insert(val + "()");
  }

  return result;
}

vector<string> generate_parentheses(int n) {
  vector<string> result;

  for (auto val : generate_parentheses_recurse(n))
    result.push_back(val);

  return result;
}

int main() {
  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int n;
    cin >> n;

    vector<string> result = generate_parentheses(n);

    for (auto val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
