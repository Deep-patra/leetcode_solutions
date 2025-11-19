#include <bits/stdc++.h>  
using namespace std;

int freq[20001];

vector<int> top_k_frequent_elements(vector<int> &nums, int k) {
  int n = nums.size();

  using pi = pair<int, int>;

  auto cmp = [](const pi &a, const pi &b) -> bool {
    if (a.second == b.second)
      return a.first < b.first;

    return a.second < b.second;
  };

  priority_queue<pi, vector<pi>, decltype(cmp)> pq(cmp);

  memset(freq, 0, sizeof(freq));

  for (int val : nums)
    freq[val + 10000] ++;

  for (int i = 0; i < 20001; i ++)
    if (freq[i] > 0) {
      pq.push({ i - 10000, freq[i] });
    }

  vector<int> res;
  
  while (k > 0 && !pq.empty()) {
    int tp = pq.top().first;
    pq.pop();

    res.push_back(tp);
    k --;
  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
      cin >> nums[i];

    vector<int> res = top_k_frequent_elements(nums, k);

    for (int val : res)
      cout << val << " ";
    cout << '\n';
  }

  return 0;
}
