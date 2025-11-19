#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool initialized = 0;

vector<vector<int>> find_prime_pairs(int n) {

  if (!initialized) {

    primes = vector<int>(1e6 + 1, 1);

    primes[0] = primes[1] = 0;

    for (int i = 2; i * i <= 1e6; i++) {
      if (primes[i]) {
        for (int j = i * i; j <= 1e6; j += i)
          primes[j] = 0;
      }
    }

    initialized = 1;
  }

  vector<vector<int>> pairs;

  for (int i = 1; i <= n >> 1; i++) {
    if (primes[i] && primes[n - i]) {
      pairs.push_back({i, n - i});
    }
  }

  return pairs;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<vector<int>> pairs = find_prime_pairs(n);
    for (auto &p : pairs) {
      cout << p[0] << " " << p[1] << " ";
    }

    cout << endl;
  }

  return 0;
}
