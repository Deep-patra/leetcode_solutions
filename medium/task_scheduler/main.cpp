#include <bits/stdc++.h>  
using namespace std;

// INFO: Complete the Implementation
int least_interval(vector<char> &tasks, int n) {
  int len = tasks.size();

  int freq[26];
  memset(freq, 0, sizeof(freq));

  for (char &c : tasks)
    freq[c - 'A']++;

  priority_queue<int> pq;

  for (int f : freq)
    if (f != 0) pq.push(f);

  int res = 0, rem = 0;

  int tp = pq.top();
  pq.pop();

  res = (tp * n) + 1;
  rem = (tp - 1) * n;

  while (!pq.empty()) {

    int top = pq.top();
    pq.pop();


  }

  return res;
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t --;

    int len, n;
    cin >> len >> n;

    vector<char> tasks(len);
    for (int i = 0; i < len; i ++)
      cin >> tasks[i];

    int res = least_interval(tasks, n);
    cout << res << '\n';
  }

  return 0;
}
