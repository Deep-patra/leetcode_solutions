#include <bits/stdc++.h>
using namespace std;

#define usl unordered_set<long long>
#define vi vector<int>

typedef long long ll;

void find_good_numbers(int n, int k, int pos, vector<int> &curr,
                       usl &good_numbers) {

  // if the pos have passed the midway
  if ((n & 1) && pos > (n >> 1) || !(n & 1) && pos > (n >> 1) - 1) {

    ll num = 0, power = pow(10, n - 1);

    for (int i = 0; i < n; i++) {
      num += curr[i] * power;
      power /= 10;
    }

    if (num % k == 0)
      good_numbers.insert(num);

    return;
  }

  for (int i = 0; i <= 9; i++) {
    if (pos == 0 && i == 0)
      continue;

    curr[pos] = curr[n - 1 - pos] = i;

    find_good_numbers(n, k, pos + 1, curr, good_numbers);

    curr[pos] = curr[n - 1 - pos] = 0;
  }
}

// TODO: Complete the implemenation of the algorithm
// INFO: Could be solved using enumeration + Permutations & Combinations
ll count_good_integers(int n, int k) {
  usl good_numbers;
  vi curr(n, 0);

  find_good_numbers(n, k, 0, curr, good_numbers);

  ll result = 0;

  count_arrangements(good_numbers);

  return result;
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    ll cnt = count_good_integers(n, k);
    cout << cnt << '\n';
  }

  return 0;
}
