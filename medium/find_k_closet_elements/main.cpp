#include <bits/stdc++.h>
using namespace std;

vector<int> find_closet_elements(vector<int> &arr, int k, int x) {
  int n = arr.size();

  typedef pair<int, int> pi;

  auto cmp = [](pi a, pi b) {
    if (a.first == b.first)
      return a.second > b.second;

    return a.first > b.first;
  };

  priority_queue<pi, vector<pi>, decltype(cmp)> pq(cmp);

  for (int val : arr)
    pq.push({abs(val - x), val});

  vector<int> res;

  while (!pq.empty() && k > 0) {
    res.push_back(pq.top().second);
    pq.pop();

    k--;
  }

  sort(res.begin(), res.end());

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    vector<int> res = find_closet_elements(arr, k, x);

    for (int val : res)
      cout << val << " ";
    cout << endl;
  }

  return 0;
}
