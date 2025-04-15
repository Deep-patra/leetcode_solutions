#include <bits/stdc++.h>
using namespace std;

// INFO: Boyer Moore's Voting algorthim to find the majority element
int moore_voting(vector<int> &nums) {
  int cand = nums[0], voting = 1;

  for (int i = 1; i < nums.size(); i++) {
    if (voting == 0) {
      cand = nums[i];
      voting = 1;
    } else {
      if (nums[i] == cand)
        voting++;

      else
        voting--;
    }
  }

  return cand;
}

// INFO: Runtime 0ms
int minimal_index(vector<int> &nums) {
  int cand = moore_voting(nums);

  int count = 0;
  for (int i = 0; i < nums.size(); i++)
    if (nums[i] == cand)
      count++;

  int curr_freq = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (cand == nums[i])
      curr_freq++;

    if (curr_freq > ((i + 1) / 2) &&
        count - curr_freq > ((nums.size() - (i + 1)) / 2))
      return i;
  }

  return -1;
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

    int result = minimal_index(nums);
    cout << result << '\n';
  }

  return 0;
}
