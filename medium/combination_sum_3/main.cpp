#include <bits/stdc++.h>
using namespace std;

void generate_combinations(int n, int k, vector<int> &curr,
                           vector<vector<int>> &res, int prev = 0,
                           int sum = 0) {

  if (curr.size() == k && sum == n) {
    res.push_back(curr);
    return;
  }

  if (curr.size() == k && sum != n)
    return;

  if (prev == 9 && sum != n)
    return;

  for (int i = prev + 1; i < 10; i++) {
    if (i > (n - sum))
      return;

    curr.push_back(i);

    generate_combinations(n, k, curr, res, i, sum + i);

    curr.pop_back();
  }
}

vector<vector<int>> combination_sum_3(int k, int n) {

  vector<vector<int>> res;

  vector<int> curr;
  generate_combinations(n, k, curr, res, 0, 0);

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int k, n;
    cin >> k >> n;

    vector<vector<int>> res = combination_sum_3(k, n);

    for (vector<int> v : res) {
      for (int val : v)
        cout << val << " ";

      cout << endl;
    }
  }

  return 0;
}
