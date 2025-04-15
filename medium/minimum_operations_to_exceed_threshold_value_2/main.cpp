#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minimum_operations(vector<int> &nums, int k) {

  priority_queue<int, vector<int>, greater<int>> q;

  for (int val : nums)
    q.push(val);

  int ops = 0;
  while (q.top() < k) {
    int top = q.top();
    q.pop();

    int second_top = q.top();
    q.pop();

    q.push(min(top, second_top) * 2 + max(top, second_top));

    ops++;
  }

  return ops;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int result = minimum_operations(nums, k);
    cout << result << '\n';
  }

  return 0;
}
