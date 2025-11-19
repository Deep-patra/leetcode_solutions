#include <bits/stdc++.h>  
using namespace std;

// TODO: Complete the Implementation
int minimum_score(vector<int> &nums, vector<vector<int>> &edges) {

}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int m;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2, 0));
    for (int i = 0; i < m; i ++)
      cin >> edges[i][0] >> edges[i][1];

    int score = minimum_score(nums, edges);
    cout << score << '\n';
  }

  return 0;
}
