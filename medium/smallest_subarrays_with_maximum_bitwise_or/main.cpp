#include <bits/stdc++.h>
using namespace std;


// INFO: Solved But Really slow, 250+ ms runtime,
// TODO: Implement a faster approach
vector<int> smallest_subarrays(vector<int> &nums) {
  int n = nums.size();

  vector<vector<int>> one_freq(n + 1, vector<int>(64, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 64; j++) {
      if (nums[i] & (1 << j))
        one_freq[i + 1][j] += 1;

      one_freq[i + 1][j] += one_freq[i][j];
    }
  }

  auto find_max_or = [&](int l, int r) -> int {
    int num = 0;

    for (int i = 0; i < 64; i++)
      num |= (one_freq[r][i] - one_freq[l][i]) > 0 ? (1 << i) : 0;

    return num;
  };

  vector<int> res(n);

  for (int i = 0, r = 1; i < n; i++) {

    int max_or = find_max_or(i, n);
    int curr_or = find_max_or(i, r);

    while (r < n && curr_or < max_or)
      curr_or = find_max_or(i, ++r);

    res[i] = r - i;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    vector<int> res = smallest_subarrays(nums);

    for (int val : res)
      cout << val << ' ';

    cout << endl;
  }

  return 0;
}
