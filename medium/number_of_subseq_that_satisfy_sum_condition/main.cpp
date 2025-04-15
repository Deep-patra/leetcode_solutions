#include <bits/stdc++.h>
using namespace std;

const int MOD = 10e9 + 7;

static int comb[100001][100001];

void generate_combination() {

  memset(comb, 0, sizeof(comb));

  comb[0][0] = 1;

  for (int i = 1; i < 100001; i++) {
    comb[i][0] = 1;

    for (int j = 1; j <= i; j++)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
  }
}

// TODO: Implement the algorithm
int num_subseq(vector<int> &nums, int target) {
  int ways = 0;

  auto single_com = [&](int a, int b) -> bool { return a * a <= b; };

  auto it = lower_bound(nums.begin(), nums.end(), target, single_com);
}

int main() {
  int t;
  cin >> t;

  generate_combinations();

  while (t > 0) {
    t--;

    int n, target;
    cin >> n >> target;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = num_subseq(nums, target);
    cout << result << '\n';
  }

  return 0;
}
