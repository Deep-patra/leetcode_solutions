#include <bits/stdc++.h>
using namespace std;

vector<int> find_x_sum(vector<int> &nums, int k, int x) {
  int n = nums.size();

  vector<int> answers, freq(51, 0);
  answers.reserve(n - k + 1);

  auto find_top_x_elements = [&]() -> int {
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

    for (int i = 1; i < 51; i++)
      if (freq[i] > 0)
        pq.push({freq[i], i});

    int cnt = 1, sum = 0;
    while (cnt <= x && !pq.empty()) {
      sum += pq.top().first * pq.top().second;
      pq.pop();

      cnt++;
    }

    return sum;
  };

  int i = 0, j = 0;
  while (j < n) {

    while (j < n && j - i + 1 <= k)
      freq[nums[j ++]] ++;

    answers.push_back(find_top_x_elements());

    freq[nums[i ++]] --;
  }

  return answers;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    vector<int> res = find_x_sum(nums, k, x);

    for (int val : res)
      cout << val << " ";

    cout << endl;
  }

  return 0;
}
