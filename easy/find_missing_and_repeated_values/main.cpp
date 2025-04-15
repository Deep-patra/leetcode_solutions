#include <bits/stdc++.h>
using namespace std;


vector<int> find_missing_and_repeated_values(vector<vector<int>> &grid) {
  int n = grid.size();
  int nums[2501];

  memset(nums, 0, sizeof(nums));

  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) 
      nums[grid[i][j]] ++;

  int missing = -1, repeated = -1;

  for (int i = 1; i <= n * n; i ++) {
    if (nums[i] == 0) missing = i;

    if (nums[i] == 2) repeated = i;
  }
  
  return { repeated, missing };
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    vector<int> result = find_missing_and_repeated_values(grid);
    for (int val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
