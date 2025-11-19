#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sum = 0;

void dfs(vector<int> &nums, int m, int k, vector<int> &seq, int set_bits = 0) {

  int n = nums.size();
}

int magical_sum(int m, int k, vector<int> &nums) {
  int n = nums.size();

  sum = 0;

  vector<int> seq;
  dfs(nums, m, k, seq);

  return sum;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int m, k, n;
    cin >> m >> k >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = magical_sum(m, k, nums);
    coiut << res << endl;
  }

  return 0;
}
