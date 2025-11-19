#include <bits/stdc++.h>
using namespace std;

void generate_permutations(int n, map<int, int> &m, vector<int> &curr,
                           vector<vector<int>> &res) {

  if (curr.size() == n) {
    res.push_back(curr);
    return;
  }

  for (pair<const int, int> &p : m) {
    if (p.second > 0) {
      p.second--;
      curr.push_back(p.first);

      generate_permutations(n, m, curr, res);

      curr.pop_back();
      p.second++;
    }
  }
}

vector<vector<int>> permute_unique(vector<int> &nums) {
  map<int, int> m;

  for (int val : nums)
    m[val]++;

  vector<vector<int>> res;

  vector<int> curr;

  generate_permutations(nums.size(), m, curr, res);

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

    vector<vector<int>> result = permute_unique(nums);

    for (vector<int> r : result) {
      for (int val : r)
        cout << val << " ";

      cout << endl;
    }
  }

  return 0;
}
