#include <bits/stdc++.h>
using namespace std;

int num_of_hidden_sequences(vector<int> &differences, int lower, int upper) {
  vector<long long> pref_sum(differences.size());

  pref_sum[0] = differences[0];

  long long minimum = pref_sum[0], maximum = pref_sum[0];
  for (int i = 1; i < differences.size(); i++) {
    pref_sum[i] = (long long)differences[i] + pref_sum[i - 1];
    minimum = min(minimum, pref_sum[i]);
    maximum = max(maximum, pref_sum[i]);
  }

  int result = (min(1LL * upper, 1LL * (upper - maximum)) -
                max(1LL * lower, 1LL * (lower - minimum))) +
               1;
  return result < 0 ? 0 : result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, lower, upper;
    cin >> n >> lower >> upper;

    vector<int> diff(n);
    for (int i = 0; i < n; i++)
      cin >> diff[i];

    int result = num_of_hidden_sequences(diff, lower, upper);
    cout << result << '\n';
  }

  return 0;
}
