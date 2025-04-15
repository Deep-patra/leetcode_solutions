#include <bits/stdc++.h>
using namespace std;

int find_pos(vector<int> &stones, int start, int val) {
  for (int i = start; i < stones.size(); i++)
    if (stones[i] == val)
      return i;

  return -1;
}

bool can_cross_recurse(vector<int> &stones, vector<vector<int>> &memo,
                       int k = 0, int index = 0) {
  if (index >= stones.size() - 1)
    return memo[index][k] = 1;

  if (index == 0)
    return memo[index][k] =
               stones[1] == 1 ? can_cross_recurse(stones, memo, 1, 1) : 0;

  if (memo[index][k] != -1)
    return memo[index][k];

  bool result = 0;

  int pos = find_pos(stones, index, stones[index] + (k - 1));

  if (pos != -1 && k != 1)
    result |= can_cross_recurse(stones, memo, k - 1, pos);

  pos = find_pos(stones, index, stones[index] + k);

  if (pos != -1)
    result |= can_cross_recurse(stones, memo, k, pos);

  pos = find_pos(stones, index, stones[index] + k + 1);

  if (pos != -1)
    result |= can_cross_recurse(stones, memo, k + 1, pos);

  return memo[index][k] = result;
}

// bool can_cross(vector<int> &stones) {
//   vector<vector<int>> memo(stones.size(), vector<int>(stones.size(), -1));
//
//   return can_cross_recurse(stones, memo);
// }

bool dp[2001][2001];
unordered_map<int, int> m;

bool can_cross(vector<int> &stones) {
  int n = stones.size();

  if (stones[1] != 1) return 0;

  m.clear();
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++)
    m.insert({ stones[i], i });


  dp[0][0] = 1;
  dp[1][1] = 1;

  int prev_jump = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= min(n - 1, prev_jump); j ++) {
      if (dp[i][j]) {

        if (j != 1 && m.find(stones[i] + (j - 1)) != m.end()) {
          dp[m[stones[i] + j - 1]][j - 1] = 1;
          prev_jump = max(prev_jump, j - 1);
        }


        if (m.find(stones[i] + j) != m.end()) {
          dp[m[stones[i] + j]][j] = 1;
          prev_jump = max(prev_jump, j);
        }

        if (m.find(stones[i] + j + 1) != m.end()) {
          dp[m[stones[i] + j + 1]][j + 1] = 1;
          prev_jump = max(prev_jump, j + 1);
        }

      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) 
      cout << dp[i][j] << " ";

    cout << '\n';
  }


  for (int i = 0; i < n; i++)
    if (dp[n - 1][i])
      return true;

  return false;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n;
    cin >> n;

    vector<int> stones(n);
    for (int i = 0; i < n; i++)
      cin >> stones[i];

    bool result = can_cross(stones);
    cout << result << '\n';
  }

  return 0;
}
