#include <bits/stdc++.h>
using namespace std;

static vector<int> primes;
static bool is_initialized = 0;

const int MAX = 1e6 + 1;

// Using sieve of erastosthenes to generate primes
void generate_primes() {
  int n = 1e6;
  bool is_prime[MAX];

  memset(is_prime, 1, sizeof(is_prime));

  for (int p = 2; p * p <= n; p++) {
    if (is_prime[p]) {

      for (int i = p * p; i <= n; i += p) {
        is_prime[i] = 0;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (is_prime[i])
      primes.push_back(i);
  }
}

int find_pos(int num) {
  int l = 0, r = primes.size() - 1, mid, pos;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (primes[mid] == num)
      return mid;

    else if (primes[mid] < num)
      l = mid + 1;

    else {
      pos = mid;
      r = mid - 1;
    }
  }

  return pos;
}

vector<int> closest_primes(int left, int right) {
  if (!is_initialized) {
    is_initialized = 1;

    generate_primes();
  }

  int i = find_pos(left);

  if (i >= primes.size())
    return {-1, -1};

  int diff = INT_MAX, first = -1, second = -1;

  while (i + 1 < primes.size() && primes[i + 1] <= right) {
    if (primes[i] >= left && primes[i + 1] <= right) {

      if (diff > primes[i + 1] - primes[i]) {
        diff = primes[i + 1] - primes[i];

        first = primes[i];
        second = primes[i + 1];
      }
    }

    i++;
  }

  return {first, second};
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int left, right;
    cin >> left >> right;

    vector<int> result = closest_primes(left, right);
    cout << result[0] << " " << result[1] << '\n';
  }

  return 0;
}
