#include <bits/stdc++.h>  
using namespace std;

int longest_subarray(vector<int> &nums, int limit) {
  int n = nums.size(), res = 0;

  deque<int> max_que, min_que;

  for (int i = 0, start = 0; i < n; i ++) {

    while (!max_que.empty() && nums[max_que.back()] < nums[i])
      max_que.pop_back();

    while (!min_que.empty() && nums[min_que.back()] > nums[i])
      min_que.pop_back();

    min_que.push_back(i);
    max_que.push_back(i);


    while (start < i && !max_que.empty() && !min_que.empty() && nums[max_que.front()] - nums[min_que.front()] > limit) {

      if (max_que.front() == start)
        max_que.pop_front();

      if (min_que.front() == start)
        min_que.pop_front();

      start++;
    } 

    res = max(res, i - start + 1);
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, limit;
    cin >> n >> limit;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    int res = longest_subarray(nums, limit);
    cout << res << '\n';
  }

  return 0;
}
