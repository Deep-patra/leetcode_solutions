#include <bits/stdc++.h>  
using namespace std;

vector<int> max_score_indices(vector<int> &nums) {
  nums.push_back(0);

  int n = nums.size(), max_score = 0;

  vector<int> scores(n + 1, 0);

  // go from left to right
  for (int i = 0, cnt = 0; i < n; i ++) {
    scores[i] = cnt;

    if (nums[i] == 0)
      cnt ++;
  }
  
  // go from right to left
  for (int i = n - 1, cnt = 0; i >= 0; i --) {
    if (nums[i] == 1)
      cnt ++;

    scores[i] += cnt;
    max_score = max(max_score, scores[i]);
  }

  vector<int> result;

  for (int i = 0; i < n; i ++) {
    if (scores[i] == max_score)
      result.push_back(i);
  }

  return result;
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

    vector<int> res = max_score_indices(nums);

    for (int val : res)
      cout << val << " ";
    cout << endl;
  }

  return 0;
}
