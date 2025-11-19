#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> &nums) {
  int n = nums.size();

  typedef pair<int, int> pi;

  auto cmp = [](pi a, pi b) -> bool {
    if (a.second == b.second)
      return a.first > b.first;

    return a.second > b.second;
  };

  priority_queue<pi, vector<pi>, decltype(cmp)> pq(cmp);

  pq.push({nums[0], 1});

  for (int i = 1; i < n; i++) {
    int val = nums[i];

    if (pq.top().first == val) {
      pq.push({ val, 1 });
    } else {

      pi top = pq.top();

      if (val - top.first == 1) {
        pq.pop();

        pq.push({ val, top.second + 1 });
      } else {

        if (top.second < 3) return 0;

        pq.pop();
        pq.push({ val, 1 });
      }

    }
  }

  while (!pq.empty()) {
    if (pq.top().second < 3)
      return 0;
    pq.pop();
  }

  return 1;
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

    bool res = is_possible(nums);
    cout << res << '\n';
  }

  return 0;
}
