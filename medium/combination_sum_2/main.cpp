#include <bits/stdc++.h>
using namespace std;

// INFO: SOLVED But really slow
// TODO: Use a memoized recursive approach to generate combinations
vector<vector<int>> combination_sum_2(vector<int> &candidates, int target) {
  sort(candidates.begin(), candidates.end());

  vector<vector<vector<int>>> dp(31, vector<vector<int>>(0));

  for (int i = 0; i < candidates.size(); i++) {

    for (int j = target - candidates[i]; j >= 0; j--) {

      if (dp[j].size() > 0) {

        for (vector<int> comb : dp[j]) {
          comb.push_back(candidates[i]);

          // check if the combination already exists
          bool skip = 0;
          for (vector<int> c : dp[j + candidates[i]]) {
            if (comb == c) {
              skip = 1;
              break;
            }
          }

          if (!skip)
            dp[j + candidates[i]].push_back(comb);
        }
      }
    }

    if (candidates[i] <= target) {

      vector<int> c = {candidates[i]};

      bool skip = 0;
      for (vector<int> comb : dp[candidates[i]])
        if (c == comb) {
          skip = 1;
          break;
        }

      if (!skip)
        dp[candidates[i]].push_back(c);
    }
  }

  return dp[target];
}

int main() {

  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int len, target;
    cin >> len >> target;

    vector<int> candidates(len, 0);
    for (int i = 0; i < len; i++)
      cin >> candidates[i];

    vector<vector<int>> result = combination_sum_2(candidates, target);

    for (auto item : result) {
      for (auto val : item)
        cout << val << " ";
      cout << endl;
    }
  }

  return 0;
}
