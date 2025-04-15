#include <bits/stdc++.h>
using namespace std;

int maximum_candies(vector<int> &candies, long long k) {
  int l = 0, r = candies[0];

  long long sum = 0;
  for (int val : candies) {
    r = max(val, r);
    sum += val;
  }

  if (sum < k)
    return 0;

  if (k == 1) return r;

  auto get_children = [&](int amt) -> long long {
    long long res = 0;

    if (amt == 0) return 0;

    for (int val : candies) {
      res += (val / amt);
    }

    return res;
  };

  int result = 0;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    int new_k = get_children(mid);

    cout << "mid => " << mid << " and new_k => " << new_k << endl;

    if (new_k >= k) {
      result = max(result, mid);
      l = mid + 1;
    } else if (new_k == 0) {
      l = mid + 1;
    } else
      r = mid - 1;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    long long k;

    cin >> n >> k;

    vector<int> candies(n);
    for (int i = 0; i < n; i++)
      cin >> candies[i];

    int result = maximum_candies(candies, k);
    cout << result << '\n';
  }

  return 0;
}
