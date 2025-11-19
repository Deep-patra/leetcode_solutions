#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// 0 1 1 2 3 5 8
// 0 1 2 3 4 5 6
int people_aware_of_secret(int n, int delay, int forget) {

  vector<int> person(n + 1, 0);
  person[1] = 1;

  int active = 0;
  for (int i = 2; i <= n; i++) {
    if (i <= delay) {
      person[i] = person[i - 1];
      continue;
    }

    active += person[i - delay] - person[i - delay - 1];
    person[i] = active + person[i - 1];

    person[i] %= MOD;
  }

  for (int val : person)
    cout << val << " ";

  cout << endl;

  return person[n];
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, delay, forget;
    cin >> n >> delay >> forget;

    int res = people_aware_of_secret(n, delay, forget);
    cout << res << endl;
  }

  return 0;
}
