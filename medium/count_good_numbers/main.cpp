#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int count_good_numbers(ll n) {
  int primes = 4, evens = 5;

  ll res = 1, even_slots = n & 1 ? (n / 2) + 1 : n / 2;

  res *= (even_slots * evens) % MOD;
  res *= ((n - even_slots) * primes) % MOD;

  res %= MOD;

  return (int)res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    ll n;
    cin >> n;

    int result = count_good_numbers(n);
    cout << result << '\n';
  }

  return 0;
}
