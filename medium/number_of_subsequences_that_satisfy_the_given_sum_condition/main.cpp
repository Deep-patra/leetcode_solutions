#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int comb[100000];
static bool initialized = 0;

void calculate_comb() {
  comb[0] = 0;
  for (int i = 1; i < 100000; i++)
    comb[i] = (comb[i - 1] + i) % MOD;
}

// INFO: Two pointer and Combinatorics approach
int num_subsequence(vector<int> &nums, int target) {
  int n = nums.size(), res = 0;

  if (!initialized)
    calculate_comb();

  initialized = 1;

  multiset<int> s;

  for (int i = n - 1; i >= 0; i--) {

    auto it = s.upper_bound(abs(nums[i] - target));

    if (it != s.begin() && s.size() > 0) {
      int pos = distance(s.begin(), it);

      res += comb[pos];
      res %= MOD;
    }

    if (2 * nums[i] <= target)
      res += 1;

    res %= MOD;
    s.insert(nums[i]);
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = num_subsequence(nums, target);
    cout << res << endl;
  }

  return 0;
}
