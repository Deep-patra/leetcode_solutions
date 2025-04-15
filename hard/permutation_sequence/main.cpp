#include <bits/stdc++.h>
using namespace std;

static vector<string> permutations[10];
static is_initialized = 0;

void generate_permutations(int n, int mask, string &s, vector<string> &result) {

  if (mask == ((1 << n) - 1)) {
    result.push_back(s);
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!(mask & (1 << (i - 1)))) {
      s.push_back('0' + i);
      generate_permutations(n, mask | 1 << (i - 1), s, result);
      s.pop_back();
    }
  }
}

string get_permutation(int n, int k) {
  if (is_initialized) 
    return permutations[n][k - 1];

  is_initialized = 1;

  premutations[1] = { "1" };

  for (int i = 2; i < 10; i ++) {
    string s;
    vector<string> result;

    generate_permutations(i, 0, s, result);

    permuations[i] = result;
  }

  return permutations[n][k - 1];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    string result = get_permutation(n, k);
    cout << result << '\n';
  }

  return 0;
}
