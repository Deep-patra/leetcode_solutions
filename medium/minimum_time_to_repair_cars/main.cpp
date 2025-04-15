#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int freq[101] = {0}, min_rank = INT_MAX, max_rank = INT_MIN;

bool is_possible(long long time, vector<int> &ranks, int cars) {
  int total_repaired_cars = 0;

  for (int i = min_rank; i <= max_rank; i++) {
    if (freq[i] == 0)
      continue;

    // binary search to find the number of cars can be repaired
    // by the current worker
    int l = 0, r = cars, curr_cars = 0;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (1LL * i * mid * mid <= time) {
        curr_cars = max(curr_cars, mid);
        l = mid + 1;
      } else
        r = mid - 1;
    }

    total_repaired_cars += curr_cars * freq[i];

    if (total_repaired_cars >= cars)
      return true;
  }

  return total_repaired_cars >= cars;
}

// INFO: Solved with 0ms runtime
long long repair_cars(vector<int> &ranks, int cars) {
  int n = ranks.size();

  memset(freq, 0, sizeof(freq));

  for (int rank : ranks) {
    min_rank = min(min_rank, rank);
    max_rank = max(max_rank, rank);

    freq[rank]++;
  }

  ll l = 1, r = 1LL * max_rank * cars * cars, result = r;

  while (l <= r) {
    long long mid = l + (r - l) / 2;

    if (is_possible(mid, ranks, cars)) {
      result = min(result, mid);
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, cars;
    cin >> n >> cars;

    vector<int> ranks(n);
    for (int i = 0; i < n; i++)
      cin >> ranks[i];

    int result = repair_cars(ranks, cars);
    cout << result << '\n';
  }

  return 0;
}
