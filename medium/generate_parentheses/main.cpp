#include <bits/stdc++.h>
using namespace std;

void set_combine(unordered_set<string> &first, unordered_set<string> &second,
                 unordered_set<string> &result) {
  for (string f_val : first)
    for (string s_val : second)
      result.insert(f_val + s_val);
}

unordered_set<string>
generate_parenthesis_recurse(int n, vector<unordered_set<string>> &memo) {
  unordered_set<string> result;

  if (memo[n].size() != 0)
    return memo[n];

  if (n == 1) {
    result.insert("()");
    return result;
  }

  for (int i = 1; i < n; i++) {
    unordered_set<string> first = generate_parenthesis_recurse(n - i, memo);
    unordered_set<string> second = generate_parenthesis_recurse(i, memo);

    set_combine(first, second, result);
  }

  for (string val : generate_parenthesis_recurse(n - 1, memo))
    result.insert("(" + val + ")");

  memo[n] = result;

  return result;
}

vector<string> generate_parenthesis(int n) {
  vector<unordered_set<string>> memo(9);

  unordered_set<string> result = generate_parenthesis_recurse(n, memo);

  vector<string> gen;

  for (string item : result)
    gen.push_back(item);

  return gen;
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<string> result = generate_parenthesis(n);
    for (string val : result)
      cout << "\"" << val << "\"" << ", ";

    cout << '\n';
  }

  return 0;
}
