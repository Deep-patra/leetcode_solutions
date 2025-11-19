#include <bits/stdc++.h>
using namespace std;

int shortest_subarray(vector<int> &nums, int k) {
  int n = nums.size(), neg = 0, res = INT_MAX;

  // find the minimum value
  for (int val : nums)
    if (val < 0)
      neg += (-1 * val);

  vector<int> pref(n + 1, 0);
  pref[0] = neg;

  int sum = nums[0], curr_sum = nums[0];
  for (int i = 0; i < n; i++) {
    pref[i + 1] += pref[i] + nums[i];

    if (i > 0) {
      curr_sum = max(curr_sum + nums[i], nums[i]);
      sum = max(sum, curr_sum);
    }
  }

  if (sum < k)
    return -1;

  deque<int> max_que, min_que;

  int start = 0;
  for (int i = 0; i < n + 1; i++) {

    while (!max_que.empty() && pref[max_que.back()] < pref[i])
      max_que.pop_back();

    while (!min_que.empty() && pref[min_que.back()] > pref[i])
      min_que.pop_back();

    max_que.push_back(i);
    min_que.push_back(i);

    while (start < i && !max_que.empty() && !min_que.empty() &&
           pref[max_que.front()] - pref[min_que.front()] >= k) {

      res = min(res, i - start);

      if (min_que.front() == start)
        min_que.pop_front();
      if (max_que.front() == start)
        max_que.pop_front();

      start++;
    }
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int res = shortest_subarray(nums, k);
    cout << res << '\n';
  }

  return 0;
}
