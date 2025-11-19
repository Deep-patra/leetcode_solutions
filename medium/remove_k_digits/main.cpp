#include <bits/stdc++.h>
using namespace std;

// INFO: Runs at 34 ms runtime, needs a 0ms runtime
// TODO: Implement a better solution
string remove_k_digits(string num, int k) {
  int n = num.length();

  auto cmp = [&](int &a, int &b) -> bool { return num[a] < num[b]; };

  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  pq.push(0);

  for (int i = 1; i < n - 1 && k > 0; i++) {
    while (k > 0 && !pq.empty() && num[pq.top()] > num[i]) {
      num[pq.top()] = '_';
      pq.pop();

      k--;
    }

    pq.push(i);
  }

  if (k > 0) {
    while (!pq.empty() && k > 0) {
      num[pq.top()] = '_';
      pq.pop();

      k--;
    }
  }

  string res;

  for (char c : num) {
    if (res.size() == 0 && c == '0')
      continue;

    if (c != '_')
      res.push_back(c);
  }

  return res.size() == 0 ? "0" : res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string num;
    int k;
    cin >> num >> k;

    string res = remove_k_digits(num, k);
    cout << res << '\n';
  }

  return 0;
}
