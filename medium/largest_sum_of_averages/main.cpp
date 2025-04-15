#include <bits/stdc++.h>
using namespace std;

const double EPSILON = numeric_limits<double>::epsilon();

// TODO: Complete the implementation
// INFO: MIGHT USE RANGE DP
double largest_sum_of_averages(vector<int> &nums, int k) {

  double l, h, sum = 0;

  for (int val : nums)
    sum += val;

  h = sum;
  l = sum / nums.size();

  if (k == 1)
    return h;

  else if (k == nums.size())
    return l;

  auto is_possible = [&](double avg) -> int {
    int res = 0, start = 0, sum = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      double a = (double)(sum / (i - start + 1));

      if (a > avg) {
        res++;

        start = i;
        sum = nums[i];
      }
    }

    if (sum > 0)
      res++;

    cout << "avg => " << avg << " res => " << res << endl;

    return res <= k ? 1 : 0;
  };

  double result = sum;

  while (l <= h) {
    double mid = l + (h - l) / 2;

    if (is_possible(mid)) {
      result = mid;
      l = mid + 1;
    } else
      h = mid - 1;
  }

  return result;
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

    double result = largest_sum_of_averages(nums, k);
    cout << result << '\n';
  }

  return 0;
}
